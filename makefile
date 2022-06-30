CC = g++
CFLAGS = -O2 -Wall -std=c++17

%: %.cpp
	$(CC) $< $(CFLAGS) -o $@_elf

purge:
	rm -f *_elf *.out
