CC=clang++
CXXFLAGS=-O3 -Wall -Wextra -Werror -std=c++11

ts-proc:
	$(CC) -o rps source/main.cpp source/player.cpp source/playground.cpp source/input.cpp $(CXXFLAGS)

.PHONY: clean

clean:
	rm -rf source/*.o rps