# Usage:
# make        # compile all binary
# make clean  # remove ALL binaries and objects


# compiler to use
CC = gcc
RM = del	# del is for windows platfor, For Linux platform one can use rm -rf
CFLAGS = -Wall
DEPS = sort_common.h sort_algo.h
CSRC = main.c \
	$(wildcard algorithms/*.c) \
	$(wildcard common/*.c)
OBJFILES = $(CSRC:.c=.o)
TARGET = sorting_algorithms
.PHONY : clean all

clean:
	$(RM) *.o
	$(RM) common\*.o
	$(RM) algorithms\*.o
	$(RM) sorting_algorithms*

all: $(TARGET)

$(TARGET): $(OBJFILES)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJFILES) $(LDFLAGS)

