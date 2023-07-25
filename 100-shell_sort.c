#include "sort.h"

/**
 * swap_ints - Swap two integers within an array.
 * @a: first integer to be swapped.
 * @b: second integer to be swapped.
 */
void swap_ints(int *a, int *b)
{
	int tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

/**
 * shell_sort - Sort array of integers in ascending
 *              order using the shell sort algorithm.
 * @array: Array of integers.
 * @size: Array size.
 *
 * Description: Uses the Knuth interval sequence.
 */
void shell_sort(int *array, size_t size)
{
	size_t gap, b, c;

	if (array == NULL || size < 2)
		return;

	for (gap = 1; gap < (size / 3);)
		gap = gap * 3 + 1;

	for (; gap >= 1; gap /= 3)
	{
		for (b = gap; b < size; b++)
		{
			c = b;
			while (c >= gap && array[c - gap] > array[c])
			{
				swap_ints(array + c, array + (c - gap));
				c -= gap;
			}
		}
		print_array(array, size);
	}
}
