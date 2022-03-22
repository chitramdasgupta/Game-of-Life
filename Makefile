CC = gcc
CFLAGS = -Wall -Wextra -Wshadow -Wcast-qual -Wparentheses -Wpedantic -O3 -std=c99
LDFLAGS = `sdl2-config --libs`

main: main.o logic.o init.o render.o
	$(CC) $(CFLAGS) $(LDFLAGS) main.o logic.o init.o render.o -o main

main.o: main.c
	$(CC) $(CFLAGS) -c main.c

logic.o: logic.c
	$(CC) $(CFLAGS) -c logic.c

init.o: init.c
	$(CC) $(CFLAGS) -c init.c

render.o: render.c
	$(CC) $(CFLAGS) -c render.c

clean:
	rm *.o
	rm main
