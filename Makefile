all: sdl-window-test

sdl-window-test: sdl-window-test.c
	gcc sdl-window-test.c `pkg-config sdl2 --cflags --libs` -o sdl-window-test
