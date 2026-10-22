# Final Fantasy VII (PS1) decomp

Dự án tái tạo mã nguồn (decompile) của **Final Fantasy VII bản PlayStation (USA)**:
từ file thực thi trên đĩa, viết lại thành hợp ngữ rồi C, sao cho khi dịch lại cho ra
đúng từng byte như bản gốc.

> Repository này **không chứa** đĩa game, file trích từ đĩa hay hợp ngữ sinh ra từ
> chúng. Mỗi người tự dùng đĩa của mình; mọi thứ lấy từ đĩa nằm trong `disks/`,
> `asm/`, `build/` và đều bị `.gitignore` loại khỏi git.

Đây là dự án độc lập: không dựa trên mã của dự án decomp khác.

## Trạng thái

| File | Nội dung | Dựng lại khớp byte |
|---|---|---|
| `SCUS_941.63` | Chương trình chính (nạp ở 0x80010000) | ✅ toàn bộ dạng hợp ngữ |

Các overlay (field, battle, world, menu, minigame...) sẽ được thêm dần, mỗi file một
cấu hình splat trong `config/`.

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

3. Công cụ hỗ trợ decompile (tuỳ chọn): [m2c](https://github.com/matt-kempster/m2c) và
   [asm-differ](https://github.com/simonlindholm/asm-differ), clone về chỗ riêng.
   Lưu ý: gói tên `m2c` trên PyPI **không phải** m2c này.

## Dựng lại

```bash
.venv/Scripts/python tools/extract_disc.py "Final Fantasy VII (USA) (Disc 1).cue"
.venv/Scripts/python tools/build.py --split
```

`extract_disc.py` chép file từ đĩa của bạn vào `disks/us/` (bỏ qua phim). `build.py`
chạy splat (tách file thực thi thành hợp ngữ trong `asm/`), dịch bằng GNU as, liên kết
theo linker script splat sinh ra, rồi so SHA-1 với bản gốc: `SCUS_941.63: OK`.

## Cấu trúc

- `config/`: cấu hình splat cho từng file thực thi, bảng ký hiệu (`symbols.*.txt`).
- `include/`: macro hợp ngữ dùng chung.
- `src/`: mã C đã decompile (từng hàm thay cho phần hợp ngữ tương ứng).
- `tools/`: trích đĩa, dựng lại.

## Lộ trình

1. Thêm overlay vào cấu hình, mỗi file đều dựng lại khớp byte.
2. Đặt tên hàm/biến đã biết (từ quá trình làm FF7 Recompiled: driver âm thanh AKAO,
   field, trận đấu...).
3. Dựng trình biên dịch gốc (PSY-Q, GCC 2.x) để decompile từng hàm sang C khớp byte.
