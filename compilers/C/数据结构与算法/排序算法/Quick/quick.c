void quick_sort(int arr[], int low, int high)
{
	int temp;
	int i = low, j = high;
	if (low < high)
	{
		temp = arr[low];
		while (i < j)
		{
			while (j > i && arr[j] >= temp)
				--j;
			if (i < j)
			{
				arr[i] = arr[j];
				++i;
			}

			while (i < j && arr[i] < temp)
				++i;
			if (i < j)
			{
				arr[j] = arr[i];
				--j;
			}
		}
		
		arr[i] = temp;
		quick_sort(arr, low, i-1);
		quick_sort(arr, i+1, high);
	}
}
