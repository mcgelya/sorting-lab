all:
	mkdir -p out
	gcc -std=c17 main.c queue.c selection_sort.c quick_sort.c -o out/main.o
start:
	./out/main.o
debug:
	mkdir -p out
	gcc -std=c17 -fsanitize=undefined,address main.c queue.c selection_sort.c quick_sort.c -o out/main.o

clean:
	rm -rf out
data:
	./out/main.o --file data.txt

