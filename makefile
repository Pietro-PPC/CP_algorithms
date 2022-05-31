CC = g++
CFLAGS = -O2 -Wall

%: %.cpp
	$(CC) $< $(CFLAGS) -o $@_elf

purge:
	rm -f *_elf *.out
