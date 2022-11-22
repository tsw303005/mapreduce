CXX = mpicxx
CXXFLAGS = -O3 -std=c++11 -pthread

SRC_DIR = ./
INCLUDE = ./
OUT_DIR = ./

SOURCES := $(wildcard $(SRC_DIR)/*.cc)
OBJECTS := $(patsubst $(SRC_DIR)/%.cc, $(OUT_DIR)/%.o, $(SOURCES))
BIN = mapReduce

.PHONY: all clean

all: $(OBJECTS)
	$(CXX) $(CXXFLAGS) $^ -o $(BIN)

$(OUT_DIR)/%.o: $(SRC_DIR)/%.cpp
	$(CXX) $(CXXFLAGS) -I${INCLUDE} -c $< -o $@

clean:
	rm $(OBJECTS)
	rm $(BIN)
