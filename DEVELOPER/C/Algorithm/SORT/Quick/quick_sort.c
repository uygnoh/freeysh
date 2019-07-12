#include <stdio.h>
#define N 7
void quick_sort(int arr[], int left, int right)
{
    int i = left;
    int j = right;
    int pivot = arr[(left+right)/2];
    while (i <= j)
    {
        while (arr[i] < pivot)
            i++;
        while (arr[j] > pivot)
            j--;
        if (i <= j)
        {
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
            i++;
            j--;
        }
    }
    if (left < j)
        quick_sort(arr, left, j);
    if (i < right)
        quick_sort(arr, i, right);

}



int main()
{
    int i;
    int arr[N] = {32,12,56,78,76,45,36};

    printf ("排序前 \n");
    for (i=0; i<N; i++)
        printf("%d\t",arr[i]);

    quick_sort(arr, 0, N-1);  

    printf ("\n排序后 \n");
    for (i=0; i<N; i++)
        printf("%d\t", arr[i]); 
    printf("\n");

    return 0;
}
