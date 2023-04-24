#include "sort.h"

/**
 * selection_sort - sort array, ascending, selection sort
 * @array: the array
 * @size: size of array
 */

void selection_sort(int *array, size_t size)
{
	int i, j, min;

	if (array == NULL || size == 0)
		return;

	for (i = 0; i < (size - 1); i++)
	{
		min = i;
		for (j = i + 1; j < size; j++)
		{
			if (copy[i + 1] < copy[i])
				min = j;
			if (min != i)
			{

