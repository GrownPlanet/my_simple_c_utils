# Compiler
CC = gcc
# Compiler flags
CFLAGS = -Wall -Isrc/headerfiles
# Output directory
OUT_DIR = bin

# Source files
SRCS := $(wildcard src/*.c) $(wildcard src/sourcefiles/*.c)

# Object files
OBJS := $(patsubst src/%.c,$(OUT_DIR)/%.o,$(SRCS))

# Executable name
EXEC = out

# Default target
all: $(EXEC)

# Create output directories if they don't exist
$(shell mkdir -p $(OUT_DIR) $(OUT_DIR)/sourcefiles)

# Compile each source file into an object file
$(OUT_DIR)/%.o: src/%.c
	$(CC) $(CFLAGS) -c $< -o $@

# Link all object files into the executable
$(EXEC): $(OBJS)
	$(CC) $(OBJS) -o $(EXEC)

# Clean up intermediate object files
clean:
	rm -f $(OUT_DIR)/*.o
