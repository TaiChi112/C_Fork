CC = gcc
CFLAGS = -Wall -Wextra -pedantic -std=c99

bin/main.exe: build/main.o
	$(CC) $(CFLAGS) -o $@ $^

build/main.o: src/main.c
	$(CC) $(CFLAGS) -c $< -o $@

all: bin/main.exe

run: all
	./bin/main.exe

clean:
	rm -f build/*.o bin/*.exe