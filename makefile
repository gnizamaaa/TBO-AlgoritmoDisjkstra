PNAME=trab2
CC=gcc
CC_FLAGS=-Wall \
		 -g    \
#		 -ansi
#		 -Wextra
#		 -pedantic
CC_LIBS=-lm

.PHONY: all clean

all: edcare.out

edcare.out:
	$(CC) $(CC_FLAGS) ./src/*.c -o ./$(PNAME) -I ./headers $(CC_LIBS)

clean:
	@ rm -rf ./*.o ./*.out
