void selection_sort(int *a, int n) {
    for (int i = 0; i < n - 1; ++i) {
        int ind = i;
        for (int j = i + 1; j < n; ++j) {
            if (a[j] < a[ind]) {
                ind = j;
            }
        }
        if (ind != i) {
            int tmp = a[ind];
            a[ind] = a[i];
            a[i] = tmp;
        }
    }
}
