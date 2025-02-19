CC=clang
CFLAGS=-O2 -Wall -Wextra -std=c99 -g
LDFLAGS=

.PHONY: all clean

all: clean wf

wf: wf.o
	$(CC) $(CFLAGS) $^ -o $@ $(LDFLAGS)

wf.o: wf.c wf.h
	$(CC) $(CFLAGS) -c $<

clean:
	rm -f *.o wf
