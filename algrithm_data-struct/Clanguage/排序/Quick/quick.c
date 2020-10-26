void quick_sort(int *a, int left, int right)
{
    if (left >= right)
        return;
    int i = letf;
    int j = right;
    int key = a[left];

    while (i < j) {
        while (i < j && key <= a[j])
            j--;

        a[i] = a[j];

        while (i < j && key >= a[i])
            i++;

        a[j] = a[i];
    }

    a[i] = key;

    quick_sort(a, left, i-1);
    quick_sort(a, i+1, right);
}
