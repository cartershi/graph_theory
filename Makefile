SRC = ./3.2.17_stable_match.cpp

CFLAGS := -g -Wall -Werror -Wfatal-errors

all:
	g++ $(CFLAGS) $(SRC) -o ./result 
