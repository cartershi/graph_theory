SRC = ./3.2.22_Hopcroft_Karp_algorithm.cpp


CFLAGS := -g -Wall -Werror -Wfatal-errors

all:
	g++ $(CFLAGS) $(SRC) -o ./result

clean:
		@rm -f result
