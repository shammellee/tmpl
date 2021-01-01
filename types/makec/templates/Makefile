PROJECT_NAME := main
SRC_DIR      := src
SOURCES      := $(wildcard $(SRC_DIR)/*.c)
HEADERS      := $(wildcard $(SRC_DIR)/*.h)
BUILD_DIR    := build
PROGRAM      := $(BUILD_DIR)/$(PROJECT_NAME)

CFLAGS :=
CFLAGS += -std=c99
CFLAGS += -Wall
CFLAGS += -Werror
CFLAGS += -Wextra
CFLAGS += -pedantic
CFLAGS += -O0

all: $(PROGRAM)
.PHONY: all

$(PROGRAM): $(SOURCES) $(HEADERS) | $(BUILD_DIR)
	$(CC) $(CFLAGS) $^ -o $@

$(BUILD_DIR):
	mkdir -p $@

dev: CFLAGS += -DDEBUG
dev: run
.PHONY: dev

run: $(PROGRAM)
	./$<
.PHONY: run

test:
	valgrind --leak-check=full $(PROGRAM)

clean:
	rm -rf $(BUILD_DIR)
.PHONY: clean

