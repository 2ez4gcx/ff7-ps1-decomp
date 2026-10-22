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

Chương trình chính (`SCUS_941.63`) được chia làm ba file C theo cách nó được dịch
(`tools/psyq.py`, bảng `FILE_OPTIONS`):

| File | Vùng | `cc1` | maspsx |
|---|---|---|---|
| `src/main/text.c` | 0x800110B8–0x80029A4F, mã của game | `-O2 -G8` | `-G8`, ASPSX 2.34 |
| `src/main/akao.c` | 0x80029A50–0x80036297, driver âm thanh AKAO | `-O2 -G0` | `-G0`, ASPSX 2.21 |
| `src/main/lib.c` | 0x80036298–0x80048D17, thư viện PSY-Q | `-O2 -G0` | `-G0`, ASPSX 2.34 |

Cách các tham số được chốt:

- **ASPSX của `text.c` nằm trong [2.30, 2.56)**: từ 2.30 trình hợp dịch gộp `%lo` vào
  lệnh nạp (`lw $v0, %lo(x)($v0)` thay vì `addiu` + `lw`), còn tới 2.56 thì `li` của
  hằng 16 bit không dấu vẫn ra `ori` như game. 2.34 là một giá trị trong khoảng đó.
- **AKAO dùng ASPSX cũ hơn 2.30**: trước một lệnh mở rộng qua `$at` (`sh $v0, x` thành
  `lui $at` + `sh`) dùng ngay thanh ghi vừa nạp, game có thêm một `nop`; chỉ ASPSX dưới
  2.30 làm vậy. 2.21 là một giá trị trong khoảng đó. Có lẽ Square dịch driver này riêng
  bằng bộ công cụ cũ hơn.
- **`-G8` chỉ cho `text.c`**: không hàm nào từ 0x80029A50 trở đi dùng `$gp`, kể cả với
  biến 1–4 byte nằm ngay cạnh `$gp`.
- **Biến ngoài ở xa `$gp`**: một biến nhỏ mà game truy cập bằng `lui`/`%lo` (vì địa chỉ
  cách `$gp` quá ±32 KB, hoặc vì trong mã gốc nó là một phần của mảng/struct) được
  `psyq.py` bỏ kích thước khỏi dòng `.extern`, để maspsx không đưa nó qua `$gp`.

`INCLUDE_ASM` dùng kiểu `maspsx_hack` của splat: GCC 2.6.3 đưa khối `asm` cấp ngoài cùng
lên trước các hàm C xung quanh, nên mỗi `INCLUDE_ASM` được bọc trong một hàm giả mà
maspsx gỡ ra, giữ đúng thứ tự.

## Viết lại một hàm

- `tools/match.py thu.c` dịch file như `build.py` dịch và so **từng từ** của mỗi hàm với
  game, sau khi điền địa chỉ như trình liên kết (lấy từ `build/us/scus_941.63.elf`, nên
  chạy `build.py` trước). Hàm cần dữ liệu riêng (chuỗi, bảng tĩnh) được báo riêng. Lời
  gọi trong Python: `match.check(file, like='src/main/akao.c')` dịch theo tham số của
  file được nêu.
- `tools/auto_decomp.py --max 48 --limit 600` cho m2c viết nháp từng hàm còn là hợp ngữ
  (nhỏ trước), giữ bản nào khớp: thay `INCLUDE_ASM` bằng C và thêm khai báo, cả nguyên
  mẫu của chính hàm đó, vào `src/main/decls.h`. Khi nguyên mẫu mới thay một khai báo m2c
  đoán trước đó cho nơi gọi, mọi hàm C được kiểm tra lại và hàm mới bị gỡ nếu có nơi gọi
  hết khớp. Hàm không khớp được liệt kê cùng lý do trong `build/us/auto_decomp.txt`.
- Khi đã thay xong: `tools/build.py` phải vẫn khớp byte.

Vài điều GCC 2.6.3 cần để ra đúng mã của game (rút ra từ các hàm đã khớp):

- `while (1)` thay vì `for (;;)`; đặt giá trị vào biến tạm bằng `if`/`else` rồi ghi một
  lần, thay vì toán tử `?:` trong lệnh ghi.
- Bộ lập lịch được tự do đổi chỗ một lệnh nạp qua con trỏ vào struct với một lệnh ghi
  vào biến đơn ở địa chỉ cố định (và ngược lại), nhưng không đổi chỗ hai truy cập cùng
  loại. Nên khi thứ tự nạp/ghi lệch, thử ghi qua trường của struct
  (`D_8009A104[1].unk28 = 0`) thay vì tên riêng của trường (`D_8009A18C = 0`) hoặc
  ngược lại.
- Địa chỉ cố định được giữ trong thanh ghi khi mã gốc đi qua một biến con trỏ
  (`p = &x; *p |= ...`); trường khác 0 của con trỏ hằng thì GCC tự đổi về địa chỉ cố
  định (`lui`/`%lo`).
- Vòng lặp đếm bằng `u16` ra `addu n, n, 0xFFFF` + `andi`; vị trí của `n--` trong thân
  vòng lặp quyết định thứ tự hằng được đưa ra ngoài vòng lặp.

[m2c](https://github.com/matt-kempster/m2c) cho bản C nháp từ hợp ngữ:
`python D:/FF7/toolchain/m2c/m2c.py asm/us/main/nonmatchings/<file>/<hàm>.s`.
