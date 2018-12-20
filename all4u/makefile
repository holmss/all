.PHONY :  all, clean
TARGET := $(shell basename $(shell pwd))
SRC    := $(wildcard *.c)
HDR    := $(wildcard *.h)
CXX    := gcc
CFLAGS := -pedantic -Wall -Wextra -Wpedantic -W -Wno-sign-compare -Wno-long-long -g3 -lm

all: $(TARGET)

clean:
	rm -f $(TARGET) $(SRC:%.c=%.o)

$(TARGET): $(SRC:%.c=%.o)
	$(CXX) $(CFLAGS) -o $@ $^

main.o: main.c $(HDR) 
	$(CXX) $(CFLAGS) -c main.c

%.o: %.c %.h
	$(CXX) $(CFLAGS) -c -o $@ $<
