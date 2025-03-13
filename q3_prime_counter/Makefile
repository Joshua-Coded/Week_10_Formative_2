# Compiler
CC = gcc

# Compiler flags
CFLAGS = -Wall -Wextra -I./include

# Linker flags
LDFLAGS = -pthread

# Target executable
TARGET = prime_counter

# Directories
SRC_DIR = src
OBJ_DIR = obj
INC_DIR = include

# Source files
SRCS = $(SRC_DIR)/main.c $(SRC_DIR)/prime_counter.c

# Object files
OBJS = $(patsubst $(SRC_DIR)/%.c,$(OBJ_DIR)/%.o,$(SRCS))

# Default target
all: $(OBJ_DIR) $(TARGET)

# Create object directory
$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

# Linking
$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $@ $^ $(LDFLAGS)

# Compiling
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	$(CC) $(CFLAGS) -c -o $@ $<

# Clean up
clean:
	rm -rf $(OBJ_DIR) $(TARGET)

# Phony targets
.PHONY: all clean
