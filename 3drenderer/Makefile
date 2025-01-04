# Math library, libm needs to be linked in by adding -lm to the linking stage.
build: 
	gcc -Wall -std=c99 ./src/*.c -L/usr/bin/lib/x86_64-linux-gnu -lm -lSDL2 -o renderer-linux

run:
	./renderer-linux

clean:
	rm renderer-linux

