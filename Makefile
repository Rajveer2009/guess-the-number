# Makefile for Number Guessing Game

# Compiler
CC = gcc

# Compiler flags
CFLAGS = -Wall

# Source files
SOURCES = number_guessing_game.c

# Output executable
OUTPUT = number_guessing_game

# Build the executable
all: $(OUTPUT)

$(OUTPUT): $(SOURCES)
	$(CC) $(CFLAGS) -o $(OUTPUT) $(SOURCES)

# Clean up the build files
clean:
	rm -f $(OUTPUT)

.PHONY: all clean

