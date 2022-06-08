all:
	gcc main.c circle.c -o main -W -Wall -Wno-unused-variable -std=gnu11 -pedantic -pthread
	gcc producer.c -o producer -pthread
	gcc consumer.c -o consumer -pthread
clean:
	rm -rf main
	rm -rf consumer
	rm -rf producer