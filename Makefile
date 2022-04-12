
SDL_CFLAGS = $(shell sdl2-config --cflags)
SDL_LIBS = $(shell sdl2-config --libs)
CFLAGS = -Wall -Wextra -std=c89 -pedantic -Wmissing-prototypes -Wstrict-prototypes -Wold-style-definition -O3 -g

.PHONY: run
run: yactc
	./yactc

yactc: main.o
	gcc main.o $(SDL_LIBS) -o yactc

main.o: main.c
	gcc -c main.c $(CFLAGS) $(SDL_CFLAGS)

clean:
	rm *.o yactc