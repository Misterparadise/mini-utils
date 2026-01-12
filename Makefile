# =========================================
# Makefile для mini-utils 
# =========================================


CC = gcc
CFLAGS = -Wall -Wextra -Iinclude -std=c11


SRC_DIR = src
BIN_DIR = bin


SRCS = $(SRC_DIR)/main.c $(SRC_DIR)/cat.c
TARGET = $(BIN_DIR)/cat
LINK = ./cat


all: $(BIN_DIR) $(TARGET) $(LINK)


$(BIN_DIR):
	mkdir -p $(BIN_DIR)

$(TARGET): $(SRCS)
	$(CC) $(CFLAGS) $(SRCS) -o $(TARGET)


$(LINK): $(TARGET)
	ln -sf $(TARGET) $(LINK)


clean:
	rm -rf $(BIN_DIR) $(LINK)


run: all
	$(LINK) $(ARGS)
