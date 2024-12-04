void quick_sort_recursive(int *a, int l, int r, int *count) {  // указатель на каунт чтобы меянть
    if (l >= r) {  // позиция l начало подотрезка r конец подотрезка
        return;
    }
    int pivot = a[(l + r) / 2];  // опорный элемент
    int i = l, j = r;
    while (i <= j) {
        ++(*count);
        while (a[i] < pivot) {
            ++i;
            ++(*count);
        }
        while (a[j] > pivot) {
            --j;
            ++(*count);
        }
        if (i >= j) {
            break;
        }
        int tmp = a[j];
        a[j] = a[i];
        a[i] = tmp;
        ++i;
        --j;
    }
    quick_sort_recursive(a, l, j, count);      // левая часть
    quick_sort_recursive(a, j + 1, r, count);  // правая часть
}

int quick_sort(int *a, int n) {
    int count = 0;
    quick_sort_recursive(a, 0, n - 1, &count);
    return count;
}
