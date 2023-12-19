#include "sort.h"

/**
 * integer_count - Counts the number.
 *
 * @array: The input array.
 * @size: The size of the array.
 * @range: The integer to check for occurrences.
 *
 * Return: The number of occurrences of the specified integer.
 */
int integer_count(int *array, size_t size, int range)
{
	int total = 0;
	size_t i;

	for (i = 0; i < size; i++)
	{
		if (array[i] == range)
			total++;
	}
	return (total);
}

/**
 * counting_sort - Sorts an array of integers in ascending order.
 *
 * @array: The array to be sorted.
 * @size: The size of the array.
 */
void counting_sort(int *array, size_t size)
{
	int k = 0, b = 0, r = 0;
	size_t i, c;
	int *count_array, *sorted_array;

	if (!array || size < 2)
		return;
	for (i = 0; i < size; i++)
	{
		if (array[i] > k)
		{
			k = array[i];
		}
	}
	if (k < 0)
	{
		return;
	}
	count_array = malloc(sizeof(int) * (k + 1));
	if (!count_array)
		return;
	for (c = 0; c < ((size_t)k + 1); c++)
	{
		if (c == 0)
			count_array[c] = integer_count(array, size, r);
		else
		{
			b = count_array[c - 1] + integer_count(array, size, r);
			count_array[c] = b;
		}
		r++;
	}
	print_array(count_array, (k + 1));
	sorted_array = malloc(sizeof(int) * size);
	if (!sorted_array)
	{
		free(count_array);
		return;
	}
	for (i = 0; i < size; i++)
		sorted_array[count_array[array[i]]-- - 1] = array[i];
	for (i = 0; i < size; i++)
		array[i] = sorted_array[i];
	free(sorted_array);
	free(count_array);
}
