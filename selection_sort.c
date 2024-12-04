int selection_sort(int *a, int n) {
    int count = 0;  // счетчик колва операций (количество действий внутри всех циклов)
    for (int i = 0; i < n - 1; ++i) {
        int ind = i;  // позиция минимума
        for (int j = i + 1; j < n; ++j) {
            if (a[j] < a[ind]) {
                ind = j;
            }
            ++count;
        }
        if (ind != i) {
            int tmp = a[ind];  // сохраняем старое
            a[ind] = a[i];
            a[i] = tmp;
        }
    }
    return count;
}
