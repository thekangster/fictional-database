CC = clang

CFLAGS = -Wall -Wpedantic -Werror -Wextra

all: businessdb

businessdb: map.o businessdb.o
	$(CC) $(CFLAGS) -o businessdb map.o businessdb.o

businessdb.o: businessdb.c map.h
	$(CC) $(CFLAGS) -c businessdb.c

clean:
	rm -f map.o businessdb.o map businessdb

format:
	clang-format -i -style=file *.[ch]
