#This is only for windows.
# Compiler and flags
CC = gcc
CXX = g++
CFLAGS = -Wall -Wextra  -std=c17
CXXFLAGS = -Wall -Wextra -std=c++17

# Directories
SRC_DIR = src
BUILD_DIR = build

# Source files, object files, and target executable
SRCS = $(wildcard $(SRC_DIR)/*.c $(SRC_DIR)/*.cpp)
OBJS = $(patsubst $(SRC_DIR)/%.c, $(BUILD_DIR)/%.o, $(patsubst $(SRC_DIR)/%.cpp, $(BUILD_DIR)/%.o, $(SRCS)))
TARGET = $(BUILD_DIR)/silkiC.exe

# Targets and rules
all: $(TARGET)

# Check if the build directory exists before creating it
$(TARGET): $(OBJS)
	@if not exist $(@D) mkdir $(@D)
	$(CXX) $(CXXFLAGS) $^ -o $@

$(BUILD_DIR)/%.o: $(SRC_DIR)/%.c
	@if not exist $(@D) mkdir $(@D)
	$(CC) $(CFLAGS) -c $< -o $@

$(BUILD_DIR)/%.o: $(SRC_DIR)/%.cpp
	@if not exist $(@D) mkdir $(@D)
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -rf $(BUILD_DIR)

.PHONY: all clean


