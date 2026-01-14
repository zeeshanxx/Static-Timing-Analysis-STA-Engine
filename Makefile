CXX = g++
CXXFLAGS = -std=c++17 -Wall

SRC = src/main.cpp src/sta_engine.cpp
OUT = sta

all:
	$(CXX) $(CXXFLAGS) $(SRC) -o $(OUT)

clean:
	rm -f $(OUT)
