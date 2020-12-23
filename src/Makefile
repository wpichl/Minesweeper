TARGET=minesweeper

SOURCES=$(wildcard *.c)

HEADERS=$(wildcard *.h)

SDL=-I/usr/include/SDL2 -lSDL2 -lSDL2_ttf -lSDL2_ttf -lSDL2_image -lSDL2_mixer

all: $(SOURCES) $(HEADERS)
	cc $(SOURCES) $(SDL) -o $(TARGET)

clean:
	rm -f $(TARGET)