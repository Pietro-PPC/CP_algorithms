CC = g++
CFLAGS = -O2 -Wall --std=c++17

%: %.cpp
	$(CC) $< $(CFLAGS) -o $@.out

purge:
	rm -f *.out
