#include "sort.h"

/**
 * get_gap - compute gap using knuth sequence
 * @size: array size
 * Return: the gap
 */

size_t get_gap(size_t size)
{
	size_t gap = 1;

	while (gap < size)
		gap = gap * 3 + 1;
	return ((gap - 1) / 3);
}

/**
 * shell_sort - sort array, ascending, shell sort, knuth sequence
 * @array: pointer to array
 * @size: size of array
 */

void shell_sort(int *array, size_t size)
{
	size_t i, gap, j;
	int temp;

	if (array == NULL || size == 0)
		return;

	for (gap = get_gap(size); gap; gap = (gap - 1) / 3)
	{
		for (i = gap; i < size; i++)
		{
			temp = array[i];
			for (j = i; j >= gap && array[j - gap] > temp; j -= gap)
				array[j] = array[j - gap];
			array[j] = temp;
		}
		print_array(array, size);
	}
}
