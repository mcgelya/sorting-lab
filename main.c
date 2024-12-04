#include <assert.h>  // для assert если условие не выпоняется то выдает ошибку
#include <stdio.h>
#include <string.h>  // для strcmp
#include <stdlib.h>

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
        FILE *input_file = fopen(argv[2], "r");  // открываем data.txt на чтение
        if (input_file == NULL) {
            printf("Cannot open provided file\n");
            return 0;
        }
        fscanf(input_file, "%d", &n);  // из файла
        a = malloc(sizeof(int) * n);   // создаем массив
        for (int i = 0; i < n; ++i) {
            fscanf(input_file, "%d", &a[i]);  // вводим
        }
        int *sorted_a = malloc(sizeof(int) * n);  // отсортированный массив
        for (int i = 0; i < n; ++i) {
            fscanf(input_file, "%d", &sorted_a[i]);  // заполняем отсортированнный массив
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
        fclose(input_file);  // закрыть файл
        return 0;
    }

    scanf("%d", &n);
    a = malloc(sizeof(int) * n);
    for (int i = 0; i < n; ++i) {
        scanf("%d", &a[i]);  // заполнили массив
    }

    // Построим очередь
    struct Queue *q = malloc(sizeof(struct Queue));
    q->back = NULL;
    q->front = NULL;
    for (int i = 0; i < n; ++i) {
        push(q, a[i]);
    }
    // Очистим очередь
    for (int i = 0; i < n; ++i) {
        assert(top(q) == a[i]);  // Убедимся, что построили очередь верно
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

    int count_selection = selection_sort(selection_sorted_a, n);
    int count_quick = quick_sort(quick_sorted_a, n);

    for (int i = 0; i < n; ++i) {
        assert(selection_sorted_a[i] == quick_sorted_a[i]);  // Убедимся, что отсортировали правильно
        fprintf(output_file, "%d ", selection_sorted_a[i]);
    }

    printf("Data was written to data.txt\n");

    printf("Sorted by selection_sort in %d operations\n", count_selection);
    printf("Sorted by quick_sort in %d operations\n", count_quick);

    free(a);
    free(selection_sorted_a);
    free(quick_sorted_a);
    fclose(output_file);
    return 0;
}
