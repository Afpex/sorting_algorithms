#include "sort.h"

/**
 * swap_ints - Function that swaps two int in an array.
 * @a: first int to be swapped.
 * @b: second int to be swapped.
 */
void swap_ints(int *a, int *b)
{
	int tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

/**
 * bubble_sort - func that sorts an array of int in ascending order.
 * @array: Array of integers to be sorted.
 * @size: The array size.
 *
 * Description: Prints array after every swap.
 */
void bubble_sort(int *array, size_t size)
{
	size_t z, len = size;
	bool bubbly = false;

	if (array == NULL || size < 2)
		return;

	while (bubbly == false)
	{
		bubbly = true;
		for (z = 0; z < len - 1; z++)
		{
			if (array[z] > array[z + 1])
			{
				swap_ints(array + z, array + z + 1);
				print_array(array, size);
				bubbly = false;
			}
		}
		len--;
	}
}
