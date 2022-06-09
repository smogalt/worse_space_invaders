# Compiler in use
CC = gcc

# Compiler flags:
# -Wall		for compiler warnings
CFLAGS = -Wall

# Linker flags:
# ncurses	used for the terminal interface
LFLAGS = -lncurses

# Name for both the source and object files:
TARGET = worse_space_invaders

all: $(TARGET)

$(TARGET): $(TARGET).c
	$(CC) $(CFLAGS) -o $(TARGET) $(TARGET).c $(LFLAGS)
