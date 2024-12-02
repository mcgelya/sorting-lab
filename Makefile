all:
	gcc -std=c17 main.c queue.c selection_sort.c quick_sort.c -o out/main.o

clean:
	rm -rf out/*
