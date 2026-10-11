# Mini Solar System

A simple solar system visualization built with C++ and raylib. Features eight orbiting planets, a resizable window, and adjustable simulation speed.

Planet sizes, distances, and speeds are illustrative, not scientifically accurate.

## Dependencies

On Arch Linux / CachyOS:

```bash
sudo pacman -S --needed base-devel raylib pkgconf
```

## Build and Run

```bash
g++ -std=c++17 -Wall -Wextra main.cpp -o naprendszer $(pkg-config --cflags --libs raylib)
./naprendszer
```

## Controls

- **Space** — Pause or resume
- **Up arrow** — Increase simulation speed
- **Down arrow** — Decrease simulation speed
- **Esc** — Exit
