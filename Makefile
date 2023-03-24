build:
	gcc main.c -o main
start:
	./main
buildLib:
	gcc -c lib.c -o lib.o
	gcc -shared -o lib.so lib.o