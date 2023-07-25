#include "sort.h"

/**
 * get_max - Get maximum value in an array of integers.
 * @array: Array of integers.
 * @size: size of the array.
 *
 * Return: The maximum integer in the array.
 */
int get_max(int *array, int size)
{
	int max, b;

	for (max = array[0], b = 1; b < size; b++)
	{
		if (array[b] > max)
			max = array[b];
	}

	return (max);
}

/**
 * counting_sort - Sort an array of integers in ascending order
 *                 using counting sort algorithm.
 * @array: Array of integers.
 * @size: size of the array.
 *
 * Description: Prints the counting array after setting it up.
 */
void counting_sort(int *array, size_t size)
{
	int *count, *sorted, max, r;

	if (array == NULL || size < 2)
		return;

	sorted = malloc(sizeof(int) * size);
	if (sorted == NULL)
		return;
	max = get_max(array, size);
	count = malloc(sizeof(int) * (max + 1));
	if (count == NULL)
	{
		free(sorted);
		return;
	}

	for (r = 0; r < (max + 1); r++)
		count[r] = 0;
	for (r = 0; r < (int)size; r++)
		count[array[r]] += 1;
	for (r = 0; r < (max + 1); r++)
		count[r] += count[r - 1];
	print_array(count, max + 1);

	for (r = 0; r < (int)size; r++)
	{
		sorted[count[array[r]] - 1] = array[r];
		count[array[r]] -= 1;
	}

	for (r = 0; r < (int)size; r++)
		array[r] = sorted[r];

	free(sorted);
	free(count);
}
