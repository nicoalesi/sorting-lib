CC = gcc
CFLAGS = -Wall -Wextra -c -Ofast -iquote ./include/

SRC_DIR = src
BUILD_DIR = build

SOURCES = $(wildcard $(SRC_DIR)/*.c)
OBJECTS = $(patsubst $(SRC_DIR)/%.c,$(BUILD_DIR)/%.o,$(SOURCES))
EXECUTABLE = main


.PHONY: clean


all: $(BUILD_DIR) $(EXECUTABLE)


$(BUILD_DIR):
	mkdir $(BUILD_DIR)


$(BUILD_DIR)/%.o: $(SRC_DIR)/%.c
	$(CC) $(CFLAGS) $< -o $@


$(EXECUTABLE): $(OBJECTS)
	$(CC) $^ -o $@


clean:
	rm *.o