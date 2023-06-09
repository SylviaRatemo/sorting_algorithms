#include "sort.h"

/**
 * swap - swap two elements
 * @a: first element
 * @b: second elemtn
 */

void swap(int *a, int *b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}

/**
 * bubble_sort - sort an array, ascending order, Bubble sort
 * @array: array of integers
 * @size: size of array
 */

void bubble_sort(int *array, size_t size)
{
	size_t i, j;

	if (size == 0 || array == NULL)
		return;

	for (i = 0; i < size - 1; i++)
	{
		for (j = 0; j < size - i - 1; j++)
		{
			if (array[j] > array[j + 1])
			{
				swap(&array[j], &array[j + 1]);
				print_array(array, size);
			}
		}
	}
}
