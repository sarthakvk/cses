SHELL = /usr/bin/env bash
.PHONEY: clean

CC = g++
CCFLAGS = -O2 -std=c++17

$(file):
	$(CC) $(CCFLAGS) -o $(file) $(file).cpp
clean:
	rm $(file)