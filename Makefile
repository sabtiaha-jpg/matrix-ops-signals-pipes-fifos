# Compiler and flags
CC = gcc
CFLAGS = -g -Wall -Wextra -fopenmp -Iinclude
LDFLAGS = -fopenmp -lm

# Source files
SOURCES = src/main.c src/matrix_operations.c src/process_pool.c src/file_operations.c src/communication.c
OBJECTS = $(SOURCES:.c=.o)
TARGET = bin/matrix_operations

# Default target
all: $(TARGET)

# Create binary
$(TARGET): $(OBJECTS)
	@mkdir -p bin
	$(CC) $(OBJECTS) -o $@ $(LDFLAGS)

# Compile source files
%.o: %.c
	@mkdir -p build
	$(CC) $(CFLAGS) -c $< -o $@

# Clean build files
clean:
	rm -f $(OBJECTS) $(TARGET)
	rm -rf build

# Install (create necessary directories and config)
install:
	@mkdir -p config matrices
	@if [ ! -f config/config.txt ]; then \
		echo "Creating default config file..."; \
		echo "matrix_directory=matrices/" > config/config.txt; \
		echo "max_workers=50" >> config/config.txt; \
		echo "worker_timeout=300" >> config/config.txt; \
		echo "menu_order=default" >> config/config.txt; \
	fi

# Run the program
run: all install
	./$(TARGET)

.PHONY: all clean install run
