CC = gcc
CFLAGS = -Wall -Wextra -Iinclude
TARGET = build/emulator

SRCS = src/main.c src/cpu.c src/mem.c
OBJS = build/main.o build/cpu.o build/mem.o

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJS)

build/%.o: src/%.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f build/*