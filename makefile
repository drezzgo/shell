CXX = g++
CXXFLAGS = -Iinclude -Wall -std=c++11
SRC_DIR = src
OBJ_DIR = obj
BIN_DIR = bin

SRCS = $(wildcard $(SRC_DIR)/*.cpp) $(wildcard $(SRC_DIR)/comandos/*.cpp)
OBJS = $(SRCS:$(SRC_DIR)/%.cpp=$(OBJ_DIR)/%.o)
TARGET = $(BIN_DIR)/mi_shell

all: $(TARGET)

$(TARGET): $(OBJS)
    @mkdir -p $(BIN_DIR)
    $(CXX) $(CXXFLAGS) -o $@ $^

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp
    @mkdir -p $(OBJ_DIR)/comandos
    $(CXX) $(CXXFLAGS) -c -o $@ $<

clean:
    rm -rf $(OBJ_DIR) $(BIN_DIR)

.PHONY: all clean