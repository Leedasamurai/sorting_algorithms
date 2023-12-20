#include "sort.h"

/**
 * get_digit - Gets a digit from a num.
 *
 * @number: The integer.
 * @digit: The digit position to retrieve.
 *
 * Return: The digit value at the given position.
 **/
int get_digit(long number, int digit)
{
	long i = 0L, pow = 1L, ret;

	for (i = 0; i < digit; i++)
		pow *= 10L;
	ret = ((number / pow) % 10);
	return (ret);
}

/**
 * radix_pass - Performs a pass of radix sort.
 *
 * @array: Integer array to sort.
 * @size: Size of the array.
 * @digit: The curr digit to check.
 * @new_array: Target array with the same size.
 *
 * Return: Always 1.
 */
int radix_pass(int *array, ssize_t size, int digit, int *new_array)
{
	ssize_t i;
	int buckets[10] = {0};

	for (i = 0; i < size; i++)
		buckets[get_digit(array[i], digit)]++;
	for (i = 1; i <= 9; i++)
		buckets[i] += buckets[i - 1];
	for (i = size - 1; i > -1; i--)
		new_array[buckets[get_digit(array[i], digit)]-- - 1] = array[i];
	return (1);
}

/**
 * radix_sort - Sorts an array in ascending order.
 *
 * @size: The size of the array.
 * @array: The integer array to sort.
 */
void radix_sort(int *array, size_t size)
{
	int *old_array, *new_array, *temp_ptr, *ptr, max = 0;
	size_t i, sd = 1;

	if (!array || size < 2)
		return;

	for (i = 0; i < size; i++)
		if (array[i] > max)
			max = array[i];
	while (max /= 10)
		sd++;
	old_array = array;
	new_array = ptr = malloc(sizeof(int) * size);
	if (!new_array)
		return;
	for (i = 0; i < sd; i++)
	{
		radix_pass(old_array, (ssize_t)size, i, new_array);
		temp_ptr = old_array;
		old_array = new_array;
		new_array = temp_ptr;
		print_array(old_array, size);
	}
	for (i = 0; i < size; i++)
		array[i] = old_array[i];
	free(ptr);
}

