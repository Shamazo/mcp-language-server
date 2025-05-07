CC = clang++

CXX_INCLUDE_DIRS := $(shell clang++ -E -x c++ - -v < /dev/null 2>&1 | grep -A 20 '#include <...>' | grep '^ ' | sed 's/^ //' | grep -v '(framework directory)')
CXX_INCLUDE_FLAGS := $(foreach dir,$(CXX_INCLUDE_DIRS),-isystem $(dir))
CXXFLAGS = -std=c++17 -Wall -Wextra  -Wno-error $(CXX_INCLUDE_FLAGS)
SRC = $(wildcard *.cpp)
OBJ = $(SRC:.cpp=.o)

all: program clean_program

# Exclude clean.o from the program target
program: another_consumer.o consumer.o helper.o main.o types.o
	$(CC) $(CXXFLAGS) -o $@ $^

# Ensure clean.o is only used for clean_program
clean_program: clean.o
	$(CC) $(CXXFLAGS) -o $@ $^

%.o: %.cpp
	$(CC) $(CXXFLAGS) -c $< -o $@

# Update the clean target to remove clean_program
clean:
	rm -f $(OBJ) program clean_program

.PHONY: all clean