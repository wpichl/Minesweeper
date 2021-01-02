# Minesweeper SDL

Retake of the old Windows NT 3.1 version written in C powered by SDL2

# Installation

## Debian/Ubuntu
```bash
sudo apt install libsdl2-dev libsdl2-image-dev libsdl2-ttf-dev libsdl2-mixer-dev make gcc
```

## macOS
use Homebrew to install the missing packages
```bash
/bin/bash -c "$(curl -fsSL https://raw.githubusercontent.com/Homebrew/install/HEAD/install.sh)"
brew install sdl2 sdl2_image sdl2_mixer sdl2_ttf make gcc
```

# Compiling and running

```bash
cd src/  
make
./minesweeper
```