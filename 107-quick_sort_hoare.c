#include "sort.h"

void quick_sort_hoare(int *array, size_t size)
{
	int upper_bound = size - 1;
	int lower_bound = 0;

	if (size < 2)
		return;
	
	partition_sort(array, lower_bound, upper_bound, size);

}

void partition_sort(int *array, int lower_bound, int upper_bound, size_t size)
{
	int location;

	if (lower_bound < upper_bound)
	{
		location = hoare_partition(array, lower_bound, upper_bound, size);
		partition_sort(array, lower_bound, location - 1, size);
		partition_sort(array, location + 1, upper_bound, size);
	}
}

int hoare_partition(int *array, int lower_bound, int upper_bound, size_t size)
{
	int start = upper_bound, end = lower_bound, temp;
	int pivot = array[upper_bound];

	while(start > end)
	{
		pivot = array[upper_bound];

		while (array[start] > pivot)
		{
			start--;
		}
		while (array[end] < pivot)
		{
			end++;
		}

		if (start > end)
		{
			temp = array[start];
			array[start] = array[end];
			array[end] = temp;
		}
	}
	
	temp = array[upper_bound];
	array[upper_bound] = array[end];
	array[end] = temp;

	print_array(array, size);

	return end;
}
