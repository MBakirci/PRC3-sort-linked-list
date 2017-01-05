CFLAGS=-Wall -Werror -pedantic -O3 -Icode -c
LDDFLAGS=-lpthread

MAIN_SOURCES=$(wildcard code/*.cpp)
MAIN_OBJECTS=$(MAIN_SOURCES:.cpp=.o) \
			 objects/FileStructure.o \
			 objects/Dir.o \
			 objects/File.o

TEST_LIBS=-lgtest -lgtest_main -lpthread

CC=g++

.phony: all clean

sort: $(MAIN_OBJECTS) Makefile code/FileStructure.h
	@$(CC) $(MAIN_OBJECTS) -fopenmp -o $@ $(LDDFLAGS)
	
all: sort

.cpp.o: Makefile
	$(CC) $(CFLAGS) -fopenmp $< -o $@

clean:
	@rm -rf sort code/*.o test/*.o *.bin *.txt
