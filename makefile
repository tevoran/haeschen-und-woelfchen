CC=x86_64-w64-mingw32-g++
CC_EM=em++

SRC=$(wildcard src/*.cpp)

CFLAGS=-mwindows -o windows/money_man.exe -Lwindows/libs -lSDL2 -lSDL2main -lSDL2_ttf -lSDL2_image -lopengl32 -lglu32 -Iwindows/include -static-libstdc++ -static-libgcc -pedantic -Wall -lmingw32
CFLAGS_EM=-o money_man.html --preload-file assets -O2 -s USE_SDL=2 -s USE_SDL_IMAGE=2 -s SDL2_IMAGE_FORMATS='["png"]' --preload-file assets -s USE_SDL_TTF=2
windows: $(SRC)
	$(CC) $(SRC) $(CFLAGS)

emscripten: $(SRC)
	$(CC_EM) $(SRC) $(CFLAGS_EM)
