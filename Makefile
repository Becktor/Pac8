TARGET = bin/PacEight.o
TARGETTST = bin/test.o
LIBS = -lcursesw
CC = gcc
CFLAGS = -Ofast -g -Wall

.PHONY: default all clean

all: pac test
pac: clean $(TARGET)
test: cleantst $(TARGETTST)



OBJECTS = $(patsubst %.c, %.o, $(wildcard src/*.c))
HEADERS = $(wildcard src/*.h)



%.o: %.c $(HEADERS)#
	@$(CC) $(CFLAGS) -c $< -o $@


$(TARGET): $(OBJECTS)
	@echo "Compiling PacEight.."
	@mkdir -p bin
	@$(CC) src/main/main.c $(OBJECTS) $(LIBS) $(CFLAGS) -o $@
	@echo "PacEight compiled with" $(CFLAGS)



$(TARGETTST): $(OBJECTS)
	@echo " "
	@echo "Compiling tests.."
	@mkdir -p bin
	@$(CC) test/test.c $(OBJECTS) $(LIBS) $(CFLAGS) -pg -o $@
	@echo "Tests compiled with" $(CFLAGS)


clean:
	@-rm -f src/*.o
	@-rm -f $(TARGET)

cleantst:
	@-rm -f test/*.o
	@-rm -f $(TARGETTST)
