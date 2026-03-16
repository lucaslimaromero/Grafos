all: libed myapps

libed:
	gcc -c graph.c -o graph.o

myapps:
	gcc main.c graph.o -o main

run:
	./main

clean:
	rm -f main graph.o