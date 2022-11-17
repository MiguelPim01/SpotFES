PROJ_NAME=prog

CC=gcc
CFLAGS=-lm -g -Wall

C_SOURCE=$(wildcard ./source/*.c)

H_SOURCE=$(wildcard ./source/*.h)

OBJ=$(C_SOURCE:./source/%.c=./objects/%.o)

all: $(PROJ_NAME)

$(PROJ_NAME): $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS)

./objects/%.o: ./source/%.c ./source/%.h
	$(CC) -c -o $@ $< $(CFLAGS)

./objects/main.o: ./source/main.c $(H_SOURCE)
	$(CC) -c -o $@ $< $(CFLAGS)

clean:
	rm -rf ./objects/*.o $(PROJ_NAME)