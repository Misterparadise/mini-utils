# =========================================
# mini-utils Makefile (Linux)
# =========================================

 
CC      := gcc
CFLAGS  := -Wall -Wextra -Werror -std=c11 -Iinclude

# Directories
SRC_DIR := src
BIN_DIR := bin

# Utilities
UTILS := cat wc grep


# Default target

all: $(BIN_DIR) $(UTILS)

# ---------
# cat
# ---------
cat: \
	$(SRC_DIR)/cat_main.c \
	$(SRC_DIR)/cat/cat.c \
	$(SRC_DIR)/common/io.c
	$(CC) $(CFLAGS) $^ -o $(BIN_DIR)/cat

# ------------------
# wc
# ------------------
wc: \
	$(SRC_DIR)/wc_main.c \
	$(SRC_DIR)/wc/wc.c \
	$(SRC_DIR)/common/io.c
	$(CC) $(CFLAGS) $^ -o $(BIN_DIR)/wc

grep: \
	$(SRC_DIR)/grep_main.c \
	$(SRC_DIR)/grep/grep.c \
	$(SRC_DIR)/common/io.c
	$(CC) $(CFLAGS) $^ -o $(BIN_DIR)/grep
# ----------------------
# Create bin directory
# ----------------------
$(BIN_DIR):
	mkdir -p $(BIN_DIR)

# -------------------
# Clean
# ------------------
clean:
	rm -rf $(BIN_DIR)

# -------------------
# Convenience targets
# -------------------
run-cat: cat
	./$(BIN_DIR)/cat $(ARGS)

run-wc: wc
	./$(BIN_DIR)/wc $(ARGS)

.PHONY: all clean cat wc run-cat run-wc
