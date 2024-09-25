CC=gcc
CFLAGS=-Wall -Wextra -fPIC -shared
PYTHON_CONFIG = python3-config

# Get Python-specific compilation flags and libraries
PYINCLUDE = $(shell $(PYTHON_CONFIG) --includes)
PYLIBS = $(shell $(PYTHON_CONFIG) --ldflags)

# Target shared object file (.so)
TARGET = mymodule$(shell $(PYTHON_CONFIG) --extension-suffix)

# The source file
SRC = python_bindings/mymodule.c

# Compile and link the shared library
$(TARGET): $(SRC)
	$(CC) $(CFLAGS) $(PYINCLUDE) $(PYLIBS) -o $(TARGET) $(SRC)

# Clean up generated files
clean:
	rm -f $(TARGET)

.PHONY: clean
