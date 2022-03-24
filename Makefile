CC = gcc
CFLAGS = -Wall -Wextra -Wshadow -Wcast-qual -Wparentheses -Wpedantic -O3 -std=c99
INCL = -Isrc/Include -Lsrc/lib 
LINK = -lmingw32 -lSDL2main -lSDL2

ifeq ($(shell uname), Linux)
   INCL = `sdl2-config --libs`
   LINK = 
endif

main: main.o logic.o init.o render.o
	$(CC) $(CFLAGS) $(INCL) -o main main.o logic.o init.o render.o $(LINK)

main.o: main.c
	$(CC) $(CFLAGS) $(INCL) -c main.c $(LINK)

logic.o: logic.c
	$(CC) $(CFLAGS) $(INCL) -c logic.c $(LINK)

init.o: init.c
	$(CC) $(CFLAGS) $(INCL) -c init.c $(LINK)

render.o: render.c
	$(CC) $(CFLAGS) $(INCL) -c render.c $(LINK)

clean:
	$(RM) *.o
	$(RM) main
	$(RM) main.exe
