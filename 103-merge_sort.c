#include "sort.h"

/**
 * merge - Merges two sub-arrays a single sorted array.
 *
 * @array: The original array.
 * @temp: A temp array to store merged results.
 * @left: The starting index of the left subarray.
 * @mid: The middle index separating the two subarrays.
 * @right: The ending index of the right subarray.
 */
void merge(int *array, int *temp, size_t left, size_t mid, size_t right)
{
	size_t i, j, k;

	printf("[Merging...]\n");
	printf("[left]: ");
	print_array(array + left, mid - left);
	printf("[right]: ");
	print_array(array + mid, right - mid);

	for (i = left, j = mid, k = 0; i < mid && j < right; k++)
	{
		if (array[i] <= array[j])
			temp[k] = array[i++];
		else
			temp[k] = array[j++];
	}

	while (i < mid)
		temp[k++] = array[i++];
	while (j < right)
		temp[k++] = array[j++];

	for (i = left, k = 0; i < right; i++, k++)
		array[i] = temp[k];

	printf("[Done]: ");
	print_array(array + left, right - left);
}

/**
 * merge_sort_recursive - Recursive helper function for merge sort.
 *
 * @array: The array to be sorted.
 * @temp: A temp array to store merged results.
 * @left: The starting index of the subarray.
 * @right: The ending index of the subarray.
 */
void merge_sort_recursive(int *array, int *temp, size_t left, size_t right)
{
	size_t mid;

	if (right - left <= 1)
		return;

	mid = left + (right - left) / 2;
	merge_sort_recursive(array, temp, left, mid);
	merge_sort_recursive(array, temp, mid, right);
	merge(array, temp, left, mid, right);
}

/**
 * merge_sort - Sorts an array of integers in ascending order.
 *
 * @array: The array to be sorted.
 * @size: The size of the array.
 */
void merge_sort(int *array, size_t size)
{
	int *temp;

	if (!array || size < 2)
		return;

	temp = malloc(sizeof(int) * size);
	if (!temp)
		return;

	merge_sort_recursive(array, temp, 0, size);

	free(temp);
}
