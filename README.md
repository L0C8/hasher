# hasher

Simple C++ GUI starter using wxWidgets.

Structure:
- Entry point: `src/main.cpp`
- GUI code: `src/gui/app.h`, `src/gui/app.cpp`
- Cipher placeholder: `src/cipher/cipher.h` (to be implemented)

## Build & run

```bash
cmake -S . -B build
cmake --build build
./build/hasher_gui
```

You need wxWidgets development files available on your system (detected via `wx-config`).
