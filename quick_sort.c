void quick_sort_recursive(int *a, int l, int r, int *count) {
    if (l >= r) {
        return;
    }
    int pivot = a[(l + r) / 2];
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
    quick_sort_recursive(a, l, j, count);
    quick_sort_recursive(a, j + 1, r, count);
}

int quick_sort(int *a, int n) {
    int count = 0;
    quick_sort_recursive(a, 0, n - 1, &count);
    return count;
}
