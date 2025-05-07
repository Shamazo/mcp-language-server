CC = clang++

CXX_INCLUDE_DIRS := $(shell clang++ -E -x c++ - -v < /dev/null 2>&1 | grep -A 20 '#include <...>' | grep '^ ' | sed 's/^ //' | grep -v '(framework directory)')
CXX_INCLUDE_FLAGS := $(foreach dir,$(CXX_INCLUDE_DIRS),-isystem $(dir))
CXXFLAGS = -std=c++17 -I./include -Wall -Wextra -Wno-error $(CXX_INCLUDE_FLAGS)
SRC = $(wildcard src/*.cpp)
OBJ = $(patsubst src/%,%, $(SRC:.cpp=.o))

# Adjust paths to correctly resolve source and object files
SRC_MAIN = src/main.cpp
SRC_CLEAN = src/clean.cpp
OBJ_MAIN = src/main.o
OBJ_CLEAN =  src/clean.o

all: program clean_program

# Ensure the 'program' target includes the object file for 'helper.cpp'
program: $(OBJ_MAIN) $(OBJ_OTHERS) src/helper.o src/types.o src/consumer.o src/another_consumer.o
	$(CC) $(CXXFLAGS) -o $@ $^

# Ensure the 'clean_program' target links the necessary object files
clean_program: src/clean.cpp
	$(CC) $(CXXFLAGS) -o $@ $^

$(OBJ_OTHERS): src/%.o: src/%.cpp
	$(CC) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ_MAIN) $(OBJ_CLEAN) src/helper.o src/types.o src/consumer.o src/another_consumer.o program clean_program

# Add a debug step to print the SRC_OTHERS variable
debug:
	@echo "SRC_OTHERS: $(SRC_OTHERS)"


.PHONY: all clean