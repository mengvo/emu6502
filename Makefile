CC = gcc
CFLAGS = -Wall -Wextra -Iinclude
TARGET = build/emulator

SRCS = src/main.c src/cpu.c src/mem.c
OBJS = build/cpu.o build/mem.o

TEST_TARGET = build/tests
TEST_SRCS = test/test_runner.c test/test_cpu.c test/test_mem.c
TEST_OBJS = build/test_runner.o build/test_cpu.o build/test_mem.o

all: $(TARGET)

# ------- Main Program -------
# builds executable w object files
$(TARGET): $(OBJS) build/main.o
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJS) build/main.o

# converts .c to .o
build/%.o: src/%.c
	$(CC) $(CFLAGS) -c $< -o $@

# ------- Unit Testing -------
# builds test executable w object files
$(TEST_TARGET): $(TEST_OBJS) $(OBJS)
	$(CC) $(CFLAGS) -o $(TEST_TARGET) $(TEST_OBJS) $(OBJS)

# converts .c to .o
build/test_%.o: test/test_%.c
	$(CC) $(CFLAGS) -c $< -o $@

# -------- Run Targets -------
run: all
	@./$(TARGET)

test: $(TEST_TARGET)
	@./$(TEST_TARGET)

clean:
	rm -f build/*