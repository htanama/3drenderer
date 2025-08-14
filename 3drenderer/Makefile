# gcc -Wall -std=c99 ./src/*.c -L/usr/bin/lib/x86_64-linux-gnu -lm -lSDL2 -o ./renderer-linux
# Math library, libm needs to be linked in by adding -lm to the linking stage.

# GCC-9.3.0 located in my local directory below, please make changes to this Makefile to find your GCC compiler.
CC = /home/harry/local/gcc/bin/gcc
build: 
	$(CC) -Wall -g -std=c99 ./src/*.c -L/home/harry/local/gcc/lib64 -lm -lSDL2 -o ./renderer-linux

run:
	./renderer-linux

clean:
	rm renderer-linux

