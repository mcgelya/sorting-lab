void quick_sort_recursive(int *a, int l, int r) {
    if (l >= r) {
        return;
    }
    int pivot = a[(l + r) / 2];
    int i = l, j = r;
    while (i <= j) {
        while (a[i] < pivot) {
            ++i;
        }
        while (a[j] > pivot) {
            --j;
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
    quick_sort_recursive(a, l, j);
    quick_sort_recursive(a, j + 1, r);
}

void quick_sort(int *a, int n) {
    quick_sort_recursive(a, 0, n - 1);
}
