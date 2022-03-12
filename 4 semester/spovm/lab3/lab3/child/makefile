CC = gcc
CFLAGS = -O3 -std=c11 -pedantic -W -Wall -Wextra -Wno-unused-parameter -Wno-unused-variable

all: main.c
	$(CC) $(CFLAGS) main.c -o child

clean:
	rm -rf *.o child