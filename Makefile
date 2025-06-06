CC := gcc
CFLAGS := -Wall -Wextra
TARGET := main

$(TARGET): $(TARGET).c
	$(CC) $(CFLAGS) $(TARGET).c -o $(TARGET)