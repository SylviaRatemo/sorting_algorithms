#include "sort.h"

/**
 * shell_sort - sort array, ascending, shell sort, knuth sequence
 * @array: pointer to array
 * @size: size of array
 */

void shell_sort(int *array, size_t size)
{
	size_t i;
	int gap, temp, j;

	for (gap = size/2; gap > 0; gap = gap / 2)
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
