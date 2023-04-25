#include "sort.h"

/**
 * swap - swap elements in array
 * @array - pointer to array
 * @a: first element index
 * @b: second element index
 */

size_t swap(int *array, size_t a, size_t b)
{
	int temp = array[a];
	array[a] = array[b];
	array[b] = temp;

	return (a);
}

/**
 * quick_sort - sort array, ascending, Quick sort
 * @array: the array
 * @size: size of the array
 */

void quick_sort(int *array, size_t size)
{
	size_t p = size - 1, i = 0, j;

	if (array == NULL || size == 0)
		return;

	while (array[i] < array[p] && i < p)
		i++;

	if (i < (size - 1))
	{
		p = swap(array, i, p);
		print_array(array, size);
		j = size - 1 - 1;
		while (i < j)
		{
			if (array[j] < array[p])
			{
				swap(array, i, j);
				print_array(array, size);
				i++;
			}
			j--;
		}
	}
	else
		p = i--;
}
