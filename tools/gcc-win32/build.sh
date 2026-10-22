#!/bin/sh
# Build GCC 2.6.3's cpp and cc1 for mips-sony-psx as 32-bit Windows programs,
# the compiler the game's C matches with (see docs/toolchain.md).
#
#     sh tools/gcc-win32/build.sh [TOOLCHAIN_DIR]     (default D:/FF7/toolchain)
#
# Needs Git Bash (sh, tar, patch, sed), an llvm-mingw clang targeting
# i686-w64-mingw32 and mingw32-make on PATH. Takes the official GCC source
# from ftp.gnu.org and decompals/old-gcc's psx patches at a pinned commit, the
# same recipe as its gcc-2.6.3-psx.Dockerfile, plus win32-compat.c for the BSD
# string functions Windows lacks. A 32-bit host matters: GCC 2.6.3 assumes
# HOST_WIDE_INT is the size of a pointer, as on the hosts PSY-Q ran on.
set -e
HERE=$(cd "$(dirname "$0")" && pwd)
TOOLS=${1:-D:/FF7/toolchain}
OLD_GCC_COMMIT=cf70ec58bce58128732062bc9930045c82904cbb
GCC_SHA256=71f673849f4dc7f20aba6ba1ecb6221c6704ef3152779aef15602e974ae3c140

mkdir -p "$TOOLS/dl/gcc" "$TOOLS/build-gcc"
tarball="$TOOLS/dl/gcc/gcc-2.6.3.tar.bz2"
[ -f "$tarball" ] || curl -sSfL -o "$tarball" https://ftp.gnu.org/old-gnu/gcc/gcc-2.6.3.tar.bz2
echo "$GCC_SHA256 *$tarball" | sha256sum -c -

if [ ! -d "$TOOLS/old-gcc" ]; then
    git clone -q https://github.com/decompals/old-gcc.git "$TOOLS/old-gcc"
fi
git -C "$TOOLS/old-gcc" checkout -q "$OLD_GCC_COMMIT"
patches="$TOOLS/old-gcc/patches"

cd "$TOOLS/build-gcc"
rm -rf gcc-2.6.3
tar --force-local -xjf "$tarball"
cd gcc-2.6.3
chmod -R u+w .
sed -i -- 's/include <varargs.h>/include <stdarg.h>/g' *.c
patch -u -p1 obstack.h -i "$patches/obstack-2.7.2.h.patch"
patch -u -p1 sdbout.c -i "$patches/sdbout-2.6.3.c.patch"
patch -su -p1 < "$patches/psx-2.5.7.patch"
touch insn-config.h
./configure --target=mips-sony-psx --prefix=/opt/cross --with-endian-little --with-gnu-as \
    --host=i386-pc-linux --build=i386-pc-linux > configure.log 2>&1

CC=i686-w64-mingw32-clang
CFLAGS="-std=gnu89 -O2 -Dbsd4_4 -Dmips -DHAVE_STRERROR -w -fcommon -fno-strict-aliasing \
 -Wno-error=int-conversion -Wno-error=implicit-function-declaration \
 -Wno-error=incompatible-pointer-types -Wno-error=incompatible-function-pointer-types \
 -Wno-error=implicit-int -Wno-error=return-type"
$CC -O2 -c "$HERE/win32-compat.c" -o win32-compat.o
mingw32-make cc1 cpp CC=$CC HOST_CC=$CC CFLAGS="$CFLAGS" CLIB=win32-compat.o > make.log 2>&1

# old-gcc's own checks of the result.
export TMPDIR=$(cygpath -w "${TEMP:-/tmp}")
./cc1.exe -quiet -O2 "$TOOLS/old-gcc/tests/little_endian.c" -o le.s
grep -qE 'lbu\s\$2,0\(\$4\)' le.s
./cc1.exe -quiet -O2 "$TOOLS/old-gcc/tests/section_attribute.c" -o sa.s
./cc1.exe -quiet -O2 "$TOOLS/old-gcc/tests/host_wide_int.c" -o hw.s
grep -q -- '-2147483648' hw.s
echo "built $TOOLS/build-gcc/gcc-2.6.3/cc1.exe and cpp.exe"
