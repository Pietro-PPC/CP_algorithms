CC = g++
CFLAGS = -O2

%: %.cpp
	$(CC) $< $(CFLAGS) -o $@

