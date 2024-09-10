# Compiler and flags
CXX = g++
CXXFLAGS = -I./Utility

# Directories
BUILD_DIR = Build
SRC_DIR = Source
UTIL_DIR = Utility

# Source and object files
SRCS = $(SRC_DIR)/main.cpp $(UTIL_DIR)/hash.cpp
OBJS = $(SRCS:$(SRC_DIR)/%.cpp=$(BUILD_DIR)/%.o)

# Target executable
TARGET = $(BUILD_DIR)/HASH

# Default target
all: $(TARGET)

# Rule to link object files into the final executable
$(TARGET): $(OBJS)
	@mkdir -p $(BUILD_DIR)  # Create the build directory if it doesn't exist
	$(CXX) $(CXXFLAGS) -o $@ $(OBJS)

# Rule to compile each .cpp file into a .o file
$(BUILD_DIR)/%.o: $(SRC_DIR)/%.cpp
	@mkdir -p $(BUILD_DIR)  # Create the build directory if it doesn't exist
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Rule to clean up build files
clean:
	rm -rf $(BUILD_DIR)
