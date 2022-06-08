all:
	gcc parent.c -o start -W -Wall -Wno-unused-variable -std=gnu11 -pedantic
	gcc child.c -o child
clean:
	rm -rf start
	rm -rf proc_debug
	rm -rf child
debug:
	gcc parent.c -o proc_debug -g
	gcc child.c -o child
