#include <assert.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

#include "queue.h"
#include "quick_sort.h"
#include "selection_sort.h"

int main(int argc, char *argv[]) {  // argc-количество аргументов argv-сами аргументы
    int n;
    int *a = NULL;
    if (argc > 1 && strcmp(argv[1], "--file") == 0) {
        if (argc == 2) {
            printf("Provide filename when using with --file\n");
            return 0;
        }
        FILE *input_file = fopen(argv[2], "r");
        if (input_file == NULL) {
            printf("Cannot open provided file\n");
            return 0;
        }
        fscanf(input_file, "%d", &n);
        a = malloc(sizeof(int) * n);
        for (int i = 0; i < n; ++i) {
            fscanf(input_file, "%d", &a[i]);
        }
        int *sorted_a = malloc(sizeof(int) * n);
        for (int i = 0; i < n; ++i) {
            fscanf(input_file, "%d", &sorted_a[i]);
        }
        printf("Source data:\n");
        for (int i = 0; i < n; ++i) {
            printf("%d ", a[i]);
        }
        printf("\nSorted data:\n");
        for (int i = 0; i < n; ++i) {
            printf("%d ", sorted_a[i]);
        }
        printf("\n");
        free(a);
        free(sorted_a);
        fclose(input_file);
        return 0;
    }
    printf("Enter the number of numbers: ");
    scanf("%d", &n);
    printf("Enter your numbers: ");
    a = malloc(sizeof(int) * n);
    for (int i = 0; i < n; ++i) {
        scanf("%d", &a[i]);
    }

    struct Queue *q = malloc(sizeof(struct Queue));
    q->back = NULL;
    q->front = NULL;
    for (int i = 0; i < n; ++i) {
        push(q, a[i]);
    }
    // Очистим очередь
    for (int i = 0; i < n; ++i) {
        assert(top(q) == a[i]);
        pop(q);
    }

    // Запишем в файл
    FILE *output_file = fopen("data.txt", "w");
    fprintf(output_file, "%d\n", n);
    for (int i = 0; i < n; ++i) {
        fprintf(output_file, "%d ", a[i]);
    }
    fprintf(output_file, "\n");

    int *selection_sorted_a = malloc(sizeof(int) * n);
    int *quick_sorted_a = malloc(sizeof(int) * n);
    for (int i = 0; i < n; ++i) {
        selection_sorted_a[i] = a[i];
        quick_sorted_a[i] = a[i];
    }

    clock_t start_selection = clock();
    int count_selection = selection_sort(selection_sorted_a, n);
    clock_t end_selection = clock();
    clock_t start_quick = clock();
    int count_quick = quick_sort(quick_sorted_a, n);
    clock_t end_quick = clock();

    for (int i = 0; i < n; ++i) {
        assert(selection_sorted_a[i] == quick_sorted_a[i]);
        fprintf(output_file, "%d ", selection_sorted_a[i]);
    }

    double elapsed_selection = (double)(end_selection - start_selection) / CLOCKS_PER_SEC;
    double elapsed_quick = (double)(end_quick - start_quick) / CLOCKS_PER_SEC;
    printf("Sorted by selection_sort in %.6f seconds\n", elapsed_selection);
    printf("Sorted by quick_sort in %.6f seconds\n", elapsed_quick);
    printf("Sorted by selection_sort in %d operations\n", count_selection);
    printf("Sorted by quick_sort in %d operations\n", count_quick);

    printf("Data was written to data.txt\n");

    free(a);
    free(selection_sorted_a);
    free(quick_sorted_a);
    fclose(output_file);
    return 0;
}
