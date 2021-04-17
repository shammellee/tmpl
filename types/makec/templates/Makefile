PROJECT_NAME := main
SRC_DIR      := src
LIB_DIR      := lib
SOURCES      := $(wildcard $(SRC_DIR)/*.c)
BUILD_DIR    := build
PROGRAM      := $(BUILD_DIR)/$(PROJECT_NAME)

CC := gcc

CFLAGS :=
CFLAGS += -std=c99
CFLAGS += -O0
CFLAGS += -Wall
CFLAGS += -Werror
CFLAGS += -Wextra
CFLAGS += -pedantic
CFLAGS += -I $(LIB_DIR)

LDLIBS :=
# LDLIBS += -ldl
# LDLIBS += -lpthread
# LDLIBS += -lm
# LDLIBS += -lcurl
# LDLIBS += -lncurses
# LDLIBS += -lwebsockets

all: $(PROGRAM)
.PHONY: all

$(PROGRAM): $(SOURCES) | $(BUILD_DIR)
	$(CC) $(CFLAGS) -o $@ $(SOURCES) $(LDLIBS)

$(BUILD_DIR):
	mkdir -p $@

dev: CFLAGS += -g
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

