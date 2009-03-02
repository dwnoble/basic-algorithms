# Algorithms Makefile

# Source file path
VPATH=./src

# Add new source files to the following categories to include in the DSD build
C_TEST_SOURCES := main.c test_cases.c
C_COMMON_SOURCES := mergesort.c selection.c

# Object files
C_TEST_OBJECTS := $(C_TEST_SOURCES:%.c=src/tests/%.o)
C_COMMON_OBJECTS := $(C_COMMON_SOURCES:%.c=src/common/%.o)
ALL_OBJECTS := $(C_COMMON_OBJECTS) $(C_TEST_OBJECTS)

# Compiler and linker settings
CFLAGS=-Iinc/common -Iinc/tests
LDFLAGS=
CC=gcc
LN=gcc

# Rules
all: main 

clean:
	rm src/tests/*.o src/common/*.o main

main: $(ALL_OBJECTS)
	$(LN) $(LDFLAGS) -o main $(ALL_OBJECTS)

tests/%.o : tests/%.s
	$(CC) $(CFLAGS) $< -o tests/$*.o

common/%.o : common/%.c
	$(CC) $(CFLAGS) $< -c -o common/$*.o
