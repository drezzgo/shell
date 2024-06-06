SRCDIR=.
BUILTINS_SRCDIR=$(SRCDIR)/builtins
SYMTAB_SRCDIR=$(SRCDIR)/symtab
BUILD_DIR=$(SRCDIR)/build

CC=gcc
LIBS=
CFLAGS=-Wall -Wextra -g -I$(SRCDIR)
LDFLAGS=-g

SRCS_BUILTINS=$(shell find $(SRCDIR)/builtins -name "*.c")

SRCS_SYMTAB=$(SRCDIR)/symtab/symtab.c

SRCS=main.c prompt.c node.c parser.c scanner.c source.c executor.c initsh.c  \
     pattern.c strings.c wordexp.c shunt.c                         \
     $(SRCS_BUILTINS) $(SRCS_SYMTAB)

OBJS=$(SRCS:%.c=$(BUILD_DIR)/%.o)

TARGET=shell

.PHONY: all
all: prep-build $(TARGET)

prep-build:
	mkdir -p $(BUILD_DIR)/builtins
	mkdir -p $(BUILD_DIR)/symtab

$(TARGET): $(OBJS)
	$(CC) $(LDFLAGS) -o $@ $^ $(LIBS)

depend: .depend

.depend: $(SRCS)
	$(RM) ./.depend
	$(CC) $(CFLAGS) -MM $^ > ./.depend;

include .depend

$(BUILD_DIR)/%.o : %.c
	$(CC) $(CFLAGS) -c $< -o $@

.PHONY: clean
clean:
	$(RM) $(OBJS) $(TARGET) core .depend
	$(RM) -r $(BUILD_DIR)

