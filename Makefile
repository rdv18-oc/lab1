CXX = g++
CXXFLAGS = -Wall -std=c++11
TARGET = text_processor

all: check-deps build

check-deps: 
	@command -v $(CXX) >/dev/null 2>&1 || { echo >&2 "error: g++ not install."; exit 1; }

build: 
	g++ -Wall -std=c++11 main.cpp -o $(TARGET)

clean: 
	rm -f $(TARGET)

.PHONY: all build clean check-deps