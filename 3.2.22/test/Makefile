SRC = .
CC = g++
CFLAGS := -g

SOURCE := $(wildcard $(SRC)/*.cpp)
SOURCE_O :=$(patsubst %.cpp,%,$(notdir $(SOURCE)))

$(SRC)/%: $(SRC)/%.cpp
	$(CC) $(CFLAGS) $< -o $@

all: $(SOURCE_O)

clean:
	@rm -f $(SOURCE_O)
