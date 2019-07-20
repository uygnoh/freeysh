#include <stdio.h>
void merge(int arr[], int L, int M, int R)
{
	int LEFT_SIZE = M-L;
	int RIGHT_SIZE = R-M+1;
	int left[LEFT_SIZE];
	int right[RIGHT_SIZE];
	int i, j, k;
	// 1, Fill in the left sub array
	for (i=L; i<M; i++)
		left[i-L] = arr[i];
		
	// 2, Fill in the right sub array
	for (i=M; i<=R; i++)
		right[i-M] = arr[i];
	
	// 3, Merge into the original array	
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
}


void mergeSort(int arr[], int L, int R)
{
	if (L == R)
		return;
	else
	{
		int M = (L+R)/2;
		mergeSort(arr, L, R);
		mergeSort(arr, M+1, R);
		merge(arr, L, M+1, R);
	}
}


int main(void)
{
	int arr[] = {2,9,10,8,7,4,5,4};
	int L = 0;
	int R = 7;
	int i;
	mergeSort(arr, L, R);
	for (i = 0; i <= R; i++)
		printf("%d\n", arr[i]);
	return 0;
}













