all:
	mkdir -p ./build
	gcc -o ./build/main main.c

clean:
	rm -rf ./build/*