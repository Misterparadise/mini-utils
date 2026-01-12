# =========================================
# Makefile для mini-utils (cat)
# =========================================

# Комппілятор і прапори
CC = gcc
CFLAGS = -Wall -Wextra -Iinclude -std=c11

# Директорії
SRC_DIR = src
BIN_DIR = bin

# Файли
SRCS = $(SRC_DIR)/main.c $(SRC_DIR)/cat.c
TARGET = $(BIN_DIR)/cat
LINK = ./cat

# =========================
# Основна ціль
# =========================
all: $(BIN_DIR) $(TARGET) $(LINK)

# Створення папки bin, якщо немає
$(BIN_DIR):
	mkdir -p $(BIN_DIR)

# Компіляція cat
$(TARGET): $(SRCS)
	$(CC) $(CFLAGS) $(SRCS) -o $(TARGET)

# Створення символічного посилання для зручного запуску ./cat
$(LINK): $(TARGET)
	ln -sf $(TARGET) $(LINK)

# Очищення
clean:
	rm -rf $(BIN_DIR) $(LINK)

# Швидкий запуск з аргументами
# Використовує змінну ARGS, щоб передавати файли/аргументи
run: all
	$(LINK) $(ARGS)
