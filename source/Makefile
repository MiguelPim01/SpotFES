PROJ_NAME=prog

CC=gcc
CFLAGS=-lm -g -Wall

C_SOURCE=$(wildcard *.c)

H_SOURCE=$(wildcard *.h)

OBJ=$(C_SOURCE:%.c=../objects/%.o)

all: $(PROJ_NAME)

$(PROJ_NAME): $(OBJ)
	$(CC) -o $@ $^

../objects/%.o: %.c %.h
	$(CC) -c -o $@ $< $(CFLAGS)

../objects/main.o: main.c $(H_SOURCE)
	$(CC) -c -o $@ $< $(CFLAGS)

clean:
	rm -rf ../objects/*.o $(PROJ_NAME)