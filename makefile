CC = g++
CFLAGS = -O2

%: %.cpp
	$(CC) $< $(CFLAGS) -o $@_elf

purge:
	rm -f *_elf *.out
