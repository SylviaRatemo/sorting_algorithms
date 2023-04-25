#include "sort.h"
/**
*count- number of times integer appears in an array
*@array: array given
*@size: size of array
*@range: number to check for occurance
*Return: number of occurances
*/
int count(int *array, size_t size, int range)
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
*counting_sort - counting sort algorithm
*@array: array to be sorted
*@size: size of the array
*/
void counting_sort(int *array, size_t size)
{
	int k = 0, b = 0, r = 0;
	size_t i, c;
	int *copy, *newArray;

	if (!array || size < 2)
		return;
	for (i = 0; i < size; i++)
	{
		if (array[i] > k)
		{
			k = array[i];
		}
	}
	copy = malloc(sizeof(int) * (k + 1));
	if (!copy)
		return;
	for (c = 0; c < ((size_t)k + 1); c++)
	{
		if (c == 0)
			copy[c] = count(array, size, r);
		else
		{
			b = copy[c - 1] + count(array, size, r);
			copy[c] = b;
		}
		r++;
	}
	print_array(copy, (k + 1));
	newArray = malloc(sizeof(int) * size);
	if (!newArray)
	{
		free(copy);
		return;
	}
	for (i = 0; i < size; i++)
		newArray[copy[array[i]]-- - 1] = array[i];
	for (i = 0; i < size; i++)
		array[i] = newArray[i];
	free(newArray);
	free(copy);
}
