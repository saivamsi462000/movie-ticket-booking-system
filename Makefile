CXX := g++
CXXFLAGS := -std=c++17 -Wall -Wextra -Iinclude

SRC := $(wildcard src/*.cpp)
OBJ := $(SRC:src/%.cpp=build/%.o)
TARGET := bin/booking_system

.PHONY: all clean run

all: $(TARGET)

$(TARGET): $(OBJ)
	@mkdir -p bin
	$(CXX) $(CXXFLAGS) -o $@ $^

build/%.o: src/%.cpp
	@mkdir -p build
	$(CXX) $(CXXFLAGS) -c $< -o $@

run: all
	@mkdir -p data
	./$(TARGET)

clean:
	rm -rf build bin
