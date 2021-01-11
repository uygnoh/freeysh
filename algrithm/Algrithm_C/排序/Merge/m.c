#include <stdio.h>
void merge(int arr[], int L, int M, int R)
{
    int LEFT_SIZE = M-L;
    int RIGHT_SIZE = R-M+1;
    int left[LEFT_SIZE];
    int right[RIGHT_SIZE];
    int i, j, k;

    //填上左边的数组元素
    for (i=L; i<M; i++)
        left[i-L] = arr[i];

    //填上右边的数组元素
    for (i=M; i<=R; i++)
        right[i-M] = arr[i];




    //把两个数组合并成一个数组
    i = 0; j = 0; k = L;
    while (i<LEFT_SIZE && j<RIGHT_SIZE)
    {
        if (left[i] < right[j])
        {
            arr[k] = left[i];
            i++;
            k++;
        }
        else
        {
            arr[k] = right[j];
            j++;
            k++;
        }
    }

//其它情况，直接把左边的数组或右边的数组，直接复制到新的数组中
    while (i < LEFT_SIZE)
    {
        arr[k] = left[i];
        i++;
        k++;
    }
    while (j < RIGHT_SIZE)
    {
        arr[k] = right[j];
        j++;
        k++;
    }
    
    
    //测试 ==========================================================================
    printf("test Left program finish !!!\n");
    for (i=0; i<LEFT_SIZE; i++)
        printf("%d,", left[i]);
    printf("\n");

    printf("test Right program finish !!!\n");
    for (i=0; i<RIGHT_SIZE; i++)
        printf("%d,", right[i]);
    printf("\n");
	printf("######################################################################\n");
//测试 Finish ===================================================================

}
void merge_sort(int arr[], int L, int R)
{
	if (L == R) {
		printf("LLLLLLLLL====%d,RRRRRRRR========%d\n", R, L);
		return;
	} else {
		int M = (L+R)/2;
		merge_sort(arr, L, M);
		merge_sort(arr, M+1, R);
		merge(arr, L, M+1, R);
	}
}
int main(void)
{
    int arr[] = {1,11,33,55,2,8,9,10,5,6,7,8};
    int L = 0;
    int R = 11;
    int i;
	merge_sort(arr, L, R);
    printf("hello world\n");
    for (i=0; i<=R; i++)
        printf("%d,", arr[i]);
    return 0;
}

