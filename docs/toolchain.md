# Trình biên dịch cho phần C

Game được dịch bằng bộ PSY-Q của Sony: `CCPSX` gọi `cpp`, `cc1` (GCC 2.6.3 sửa cho PS1)
và `ASPSX` (trình hợp dịch). Ở đây dùng những thứ tương đương chạy được trên Windows:

```
cpp (GCC 2.6.3) -> cc1 (GCC 2.6.3, mips-sony-psx) -> maspsx -> GNU as (mipsel-none-elf)
```

| Bước | Công cụ | Lấy ở đâu |
|---|---|---|
| Tiền xử lý, biên dịch | `cpp.exe`, `cc1.exe` (GCC 2.6.3) | Dựng bằng `tools/gcc-win32/build.sh` |
| Thay ASPSX | [maspsx](https://github.com/mkst/maspsx) commit `4ffa8b5` + `tools/maspsx-extern.patch` | `git clone`, `git apply` |
| Hợp dịch, liên kết | GNU binutils 2.40 (`mipsel-none-elf-*`) | PSn00bSDK v0.24, xem README |

`tools/psyq.py` nối các bước này; `tools/build.py` dùng nó cho mọi file `src/**/*.c`.

## Dựng GCC 2.6.3 cho Windows

```bash
sh tools/gcc-win32/build.sh D:/FF7/toolchain
```

Script lấy mã nguồn GCC chính thức (`ftp.gnu.org/old-gnu/gcc/gcc-2.6.3.tar.bz2`, SHA-256
`71f67384…3c140`) và bản vá PS1 của
[decompals/old-gcc](https://github.com/decompals/old-gcc) (commit `cf70ec5`, đúng công thức
`gcc-2.6.3-psx.Dockerfile` của họ), rồi dịch `cc1` và `cpp` bằng clang thành chương trình
**Windows 32-bit** (`i686-w64-mingw32`, có trong bộ llvm-mingw). Bản 32-bit là cần thiết:
GCC 2.6.3 coi một số nguyên máy (`HOST_WIDE_INT`) đủ chứa con trỏ, như trên các máy chạy
PSY-Q thời đó. `tools/gcc-win32/win32-compat.c` bù vài hàm chuỗi kiểu BSD mà Windows
không có. Kết quả qua được các phép thử của old-gcc; hai lần dựng cho đầu ra giống hệt
nhau.

`cc1` cần biến `TMPDIR` trỏ tới một thư mục ghi được (`psyq.py` tự đặt).

## Bản vá maspsx

ASPSX truy cập một biến ngoài nhỏ (`.extern x, 4`, kích thước ≤ `-G`) qua `$gp`; maspsx
bản gốc bỏ qua dòng `.extern`. `tools/maspsx-extern.patch` ghi nhận các biến đó (chỉ để
chọn cách truy cập, không định nghĩa chúng):

```bash
git -C D:/FF7/toolchain/maspsx apply "$PWD/tools/maspsx-extern.patch"
```

## Tham số đã khớp

Với chương trình chính (`SCUS_941.63`): `cc1 -O2 -G8`, maspsx `-G8 --expand-div`,
`--aspsx-version=2.56`. Mọi hàm đã thử cho kết quả như nhau với ASPSX từ 2.34 trở lên;
2.56 là lựa chọn tạm cho tới khi có hàm phân biệt được. Các overlay có thể cần tham số
khác (chưa có hàm C nào).

`INCLUDE_ASM` dùng kiểu `maspsx_hack` của splat: GCC 2.6.3 đưa khối `asm` cấp ngoài cùng
lên trước các hàm C xung quanh, nên mỗi `INCLUDE_ASM` được bọc trong một hàm giả mà
maspsx gỡ ra, giữ đúng thứ tự.

## Viết lại một hàm

1. Thử hàm trong một file riêng: `tools/try_c.py thu.c` dịch file và so từng lệnh với
   hợp ngữ của game (bỏ qua phần địa chỉ do relocation điền). Thêm `--show` để xem đầu
   ra của `cc1` và maspsx.
2. Khi `OK`, thay dòng `INCLUDE_ASM(..., tên_hàm);` trong `src/<mục>/text.c` bằng hàm C.
3. `tools/build.py`: mục đó phải vẫn khớp byte.

[m2c](https://github.com/matt-kempster/m2c) cho bản C nháp từ hợp ngữ:
`python D:/FF7/toolchain/m2c/m2c.py asm/us/main/nonmatchings/text/<hàm>.s`.
