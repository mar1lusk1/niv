# Compiler and flags
CC = clang
CFLAGS = -Wall -Wextra -std=c11 `pkg-config --cflags sdl2 SDL2_image`
LDFLAGS = `pkg-config --libs sdl2 SDL2_image`

# Project settings
SRC_DIR = src
OBJ_DIR = build
BIN_DIR = bin
TARGET = $(BIN_DIR)/niv

# Source files
SRCS = $(wildcard $(SRC_DIR)/*.c)
OBJS = $(patsubst $(SRC_DIR)/%.c,$(OBJ_DIR)/%.o,$(SRCS))

# Default target
all: $(TARGET)

# Linking
$(TARGET): $(OBJS) | $(BIN_DIR)
	$(CC) $(OBJS) -o $@ $(LDFLAGS)

# Compilation
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c | $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

# Create directories
$(OBJ_DIR) $(BIN_DIR):
	mkdir -p $@

# Clean up build files
clean:
	rm -rf $(OBJ_DIR) $(BIN_DIR)

.PHONY: all clean
