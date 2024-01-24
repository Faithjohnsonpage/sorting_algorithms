#include "sort.h"

void merge(int *array, int lb, int mid, int ub);

/**
 * merge_sort - Sorts an array of integers in ascending order using the
 * top-down merge sort algorithm.
 *
 * @array: Pointer to the array to be sorted.
 * @size: Size of the array.
 */

void merge_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	topDown_mergeSort(array, 0, size - 1);
}

/**
 * topDown_mergeSort - Recursively divides and sorts the array using the
 * top-down merge sort algorithm.
 *
 * @array: Pointer to the array to be sorted.
 * @lb: Index of the leftmost element in the current range.
 * @ub: Index of the rightmost element in the current range.
 */

void topDown_mergeSort(int *array, int lb, int ub)
{
	int mid;

	if (lb < ub)
	{
		mid = lb + (ub - (lb + 1)) / 2;
		topDown_mergeSort(array, lb, mid);
		topDown_mergeSort(array, mid + 1, ub);
		merge(array, lb, mid, ub);
	}
}

/**
 * merge - Merges two sorted subarrays into a single sorted array.
 *
 * @array: Pointer to the array containing the subarrays.
 * @lb: Index of the leftmost element of the first subarray.
 * @mid: Index of the rightmost element of the first subarray.
 * @ub: Index of the rightmost element of the second subarray.
 */

void merge(int *array, int lb, int mid, int ub)
{
	int n, a, k = 0;
	int i = lb, j = mid + 1;
	int *temp_arr;

	temp_arr = (int *)malloc((ub - lb + 1) * sizeof(int));

	if (temp_arr == NULL)
		return;

	printf("Merging...\n");

	printf("[left]: ");
	for (a = lb; a <= mid; a++)
	{
		printf("%d", array[a]);
		if (a < mid)
			printf(", ");
	}
	printf("\n");

	printf("[right]: ");
	for (a = mid + 1; a <= ub; a++)
	{
		printf("%d", array[a]);
		if (a < ub)
			printf(", ");
	}
	printf("\n");

	while (i <= mid && j <= ub)
	{
		if (array[i] <= array[j])
		{
			temp_arr[k] = array[i];
			i++;
		}
		else
		{
			temp_arr[k] = array[j];
			j++;
		}
		k++;
	}

	while (j <= ub)
	{
		temp_arr[k] = array[j];
		j++;
		k++;
	}
	while (i <= mid)
	{
		temp_arr[k] = array[i];
		i++;
		k++;
	}

	printf("[Done]: ");
	for (a = lb; a <= ub; a++)
	{
		printf("%d", array[a]);
		if (a < ub)
			printf(", ");
	}
	printf("\n");

	n = ub - lb + 1;

	for (a = 0; a < n; a++)
	{
		array[lb + a] = temp_arr[a];
	}

	free(temp_arr);

}
