CC = gcc
CFLAGS = -Wall -Wextra -std=c99 -g
SRC = src/main.c src/password_gen.c src/utils.c
OBJ = $(SRC:.c=.o)
TARGET = bin/password_generator

all: $(TARGET)

$(TARGET): $(OBJ)
	mkdir -p bin
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJ)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

run: $(TARGET)
	./$(TARGET)

clean:
	rm -f $(OBJ) $(TARGET)

.PHONY: all run clean
