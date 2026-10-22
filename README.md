# Final Fantasy VII (PS1) decomp

Dự án tái tạo mã nguồn (decompile) của **Final Fantasy VII bản PlayStation (USA)**:
từ file thực thi trên đĩa, viết lại thành hợp ngữ rồi C, sao cho khi dịch lại cho ra
đúng từng byte như bản gốc.

> Repository này **không chứa** đĩa game, file trích từ đĩa hay hợp ngữ sinh ra từ
> chúng. Mỗi người tự dùng đĩa của mình; mọi thứ lấy từ đĩa nằm trong `disks/`,
> `asm/`, `build/` và đều bị `.gitignore` loại khỏi git.

Đây là dự án độc lập: không dựa trên mã của dự án decomp khác.

## Trạng thái

318 file thực thi của đĩa 1 dựng lại khớp từng byte. Phần code của chương trình chính đã
đi qua cùng phiên bản trình biên dịch mà PSY-Q dùng (GCC 2.6.3, xem [docs/toolchain.md](docs/toolchain.md)):
6 hàm viết lại bằng C, các hàm còn lại vẫn là hợp ngữ (`INCLUDE_ASM`). Danh sách đầy đủ ở
`config/targets.txt`.

| File trên đĩa | Nội dung | Nạp ở |
|---|---|---|
| `SCUS_941.63` | Chương trình chính: hệ thống, CD, driver âm thanh AKAO, kernel | 0x80010000 |
| `FIELD/FIELD.BIN` | Bản đồ field: script, nền, model, hội thoại | 0x800A0000 |
| `BATTLE/BATTLE.X`, `BROM.X` | Trận đấu | 0x800A0000 |
| `BATTLE/BATINI.X`, `BATRES.X` | Vào trận, kết thúc trận | 0x801B0000 |
| `WORLD/WORLD.BIN` | Bản đồ thế giới | 0x800A0000 |
| `FIELD/ENDING.X`, `DSCHANGE.X` | Đoạn kết, màn hình đổi đĩa | 0x800A0000 |
| `MENU/*.MNU` (13 file) | Các menu: vật phẩm, phép, trang bị, materia, lưu, cửa hàng... | 0x801D0000 |
| `MINI/*.BIN` (7 file) | Minigame: `CHOCOBO`, `CONDOR`, `HIGHWAY`, `JET`, `SNOBO`, `SNOBO2`, `SUBMAR` | 0x800A0000 |
| `MAGIC/*.BIN` (289 file) | Hiệu ứng phép, triệu hồi, limit, chiêu của quái | 0x801B0000 |

**Overlay nén:** nhiều file (`*.X`, `FIELD.BIN`, `WORLD.BIN`, `MINI/*.BIN`) là một
luồng gzip sau 8 byte đầu `{u32 kích thước giải nén, u32 ...}`. Mục tiêu khớp byte của
chúng là **ảnh đã giải nén**, đúng thứ game nạp vào RAM (`build.py` tự giải nén từ đĩa
vào `disks/us/unpacked/`). Nén lại ra đúng file gốc thì cần bộ nén gzip gốc: zlib
gần đúng (khớp 1112/1116 byte ở `BROM.X`) nhưng chưa khớp hoàn toàn.

Chỉ đĩa 1 bản USA được dùng; overlay chỉ có trên đĩa 2/3 sẽ thêm sau.

## Cài đặt (Windows)

1. Python 3.12+ và môi trường riêng:

   ```bash
   python -m venv .venv
   .venv/Scripts/python -m pip install -r requirements.txt
   ```

2. Bộ công cụ GNU cho MIPS (PS1): `gcc-mipsel-none-elf-12.3.0-windows.zip` từ
   [PSn00bSDK v0.24](https://github.com/Lameguy64/PSn00bSDK/releases/tag/v0.24)
   (SHA-256 `51df48145d5ef4b396d3932b72ccba538cc605c7c7745b32c58c277aa00523c5`), giải nén
   và trỏ biến `MIPSEL_PREFIX` tới `.../bin/mipsel-none-elf-` (mặc định
   `D:/FF7/toolchain/mipsel/bin/mipsel-none-elf-`).

3. Trình biên dịch cho phần C: GCC 2.6.3 dựng thành chương trình Windows 32-bit bằng
   `tools/gcc-win32/build.sh`, cùng [maspsx](https://github.com/mkst/maspsx) có bản vá
   `tools/maspsx-extern.patch`. Chi tiết ở [docs/toolchain.md](docs/toolchain.md).

4. Công cụ hỗ trợ decompile (tuỳ chọn): [m2c](https://github.com/matt-kempster/m2c) và
   [asm-differ](https://github.com/simonlindholm/asm-differ), clone về chỗ riêng.
   Lưu ý: gói tên `m2c` trên PyPI **không phải** m2c này.

## Dựng lại

```bash
.venv/Scripts/python tools/extract_disc.py "Final Fantasy VII (USA) (Disc 1).cue"
.venv/Scripts/python tools/build.py --split
```

`extract_disc.py` chép file từ đĩa của bạn vào `disks/us/` (bỏ qua phim). `build.py`
chạy splat (tách từng file thực thi thành hợp ngữ trong `asm/`), dịch bằng GNU as, liên
kết theo linker script splat sinh ra (overlay được liên kết với ký hiệu của chương
trình chính), rồi so SHA-1 với bản gốc. Kết quả đúng: `N/N targets match`.
`build.py field battle` chỉ dựng các mục có tên bắt đầu như vậy.

Thêm một overlay: `tools/find_overlays.py` liệt kê file có mã MIPS và đoán địa chỉ nạp
(từ các lệnh `jal` gọi vào chính nó); `tools/new_overlay.py FILE ĐỊA_CHỈ TÊN` tạo cấu
hình splat và thêm vào `config/targets.txt`.

## Cấu trúc

- `config/`: cấu hình splat cho từng file thực thi, bảng ký hiệu (`symbols.*.txt`).
- `include/`: macro hợp ngữ dùng chung.
- `src/`: mã C đã decompile (từng hàm thay cho phần hợp ngữ tương ứng).
- `tools/`: trích đĩa, dựng lại.

## Lộ trình

1. ~~Thêm overlay vào cấu hình, mỗi file đều dựng lại khớp byte.~~ Xong cho đĩa 1;
   còn: overlay riêng của đĩa 2/3, kích thước BSS của từng overlay, bộ nén gzip gốc.
2. Đặt tên hàm/biến đã biết (từ quá trình làm FF7 Recompiled: driver âm thanh AKAO,
   field, trận đấu...).
3. ~~Dựng trình biên dịch gốc (PSY-Q, GCC 2.x).~~ Xong: GCC 2.6.3 + maspsx, 6 hàm đầu
   tiên đã khớp. Tiếp: decompile dần từng hàm (`tools/try_c.py`), chia `text.c` thành
   các file theo từng phần của game, dò tham số cho từng overlay.
