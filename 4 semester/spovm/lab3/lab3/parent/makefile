CC = gcc
CFLAGS = -O3 -std=c11 -pedantic -W -Wall -Wextra -Wno-unused-parameter -Wno-unused-variable

all: main.c helper.c
	$(CC) $(CFLAGS) main.c helper.c -o parent

clean:
	rm -rf *.o parent