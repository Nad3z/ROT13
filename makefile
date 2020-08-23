CXX 	  := g++
CXXFLAGS  := -pedantic-errors -Wall -Wextra -Werror
BUILD_DIR := ./build
SRC 	  := ./src/*.cpp
OUT 	  := main.out

all:
	$(CXX) $(CXXFLAGS) $(SRC) -o $(BUILD_DIR)/$(OUT)

build:
	@mkdir -p $(BUILD_DIR)

clean:
	-@rm -rvf $(BUILD_DIR)/*
