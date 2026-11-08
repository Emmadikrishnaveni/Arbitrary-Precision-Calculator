CC = gcc
CFLAGS = -Wall -Wextra
TARGET = apc

SRC = main.c apc.c add.c sub.c mul.c div.c validation.c

$(TARGET): $(SRC)
	$(CC) $(CFLAGS) $(SRC) -o $(TARGET)

clean:
	rm -f $(TARGET)