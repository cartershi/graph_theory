SRC = ./3.2.9_weighted_match.cpp

CFLAGS := -g -Wall -Werror -Wfatal-errors

all:
	g++ $(CFLAGS) $(SRC) -o ./result 
