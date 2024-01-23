#include "sort.h"

/**
 * quick_sort - Sorts an array of integers using the Quick Sort algorithm.
 * @array: Pointer to the array to be sorted.
 * @size: Size of the array.
 */

void quick_sort(int *array, size_t size)
{
	int upper_bound = size - 1;
	int lower_bound = 0;

	if (array == NULL || size < 2)
		return;

	partition_sort(array, lower_bound, upper_bound, size);

}

/**
 * partition_sort - Recursively sorts partitions of an array using Quick Sort.
 * @array: Pointer to the array to be sorted.
 * @lower_bound: The lower bound of the current partition.
 * @upper_bound: The upper bound of the current partition.
 * @size: Size of the array.
 */

void partition_sort(int *array, int lower_bound, int upper_bound, size_t size)
{
	int location;

	if (lower_bound < upper_bound)
	{
		location = lomuto_partition(array, lower_bound, upper_bound, size);
		partition_sort(array, lower_bound, location - 1, size);
		partition_sort(array, location + 1, upper_bound, size);
	}
}

/**
 * lomuto_partition - Partitions an array using the Lomuto partition scheme.
 * @array: Pointer to the array to be partitioned.
 * @lower_bound: The lower bound of the current partition.
 * @upper_bound: The upper bound of the current partition.
 * @size: Size of the array.
 *
 * Return: The final position of the pivot after partitioning.
 */

int lomuto_partition(int *array, int lower_bound, int upper_bound, size_t size)
{
	int i = lower_bound - 1, j = lower_bound, temp;
	int pivot = array[upper_bound];

	while (j <= upper_bound - 1)
	{
		if (array[j] <= pivot)
		{
			i++;
			if (i != j)
			{
				temp = array[i];
				array[i] = array[j];
				array[j] = temp;

				print_array(array, size);
			}
		}
		j++;
	}
	if (i + 1 != upper_bound)
	{
		temp = array[i + 1];
		array[i + 1] = array[upper_bound];
		array[upper_bound] = temp;

		print_array(array, size);
	}

	return (i + 1);
}
