TARGET = bin/PacEight.o

LIBS = -lcurses
CC = gcc
CFLAGS = -Ofast -g -Wall

.PHONY: default all clean

default: clean $(TARGET)
all: default


OBJECTS = $(patsubst %.c, %.o, $(wildcard src/*.c))
HEADERS = $(wildcard src/*.h)

%.o: %.c $(HEADERS)
	@$(CC) $(CFLAGS) -c $< -o $@

.PRECIOUS: $(TARGET) $(OBJECTS)

$(TARGET): $(OBJECTS)
	@echo "Compiling PacEight.."
	@mkdir -p bin
	@$(CC) $(OBJECTS) $(LIBS) -o $@
	@echo "PacEight compiled with" $(CFLAGS)



clean:
	@-rm -f src/*.o
	@-rm -f $(TARGET)
