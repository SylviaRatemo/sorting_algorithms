#include "sort.h"

/**
 * max - get maximum in array
 * @array: pointer to array
 * @size: size of array
 */
int max(int *array, int size)
{
	int i, max = array[0];

	for (i = 0; i < size; i++)
	{
		if (array[i] > max)
			max = array[i];
	}
	return (max);
}

/**
 * count_sort - sort based on digit
 * @array: pointer to array
 * @n: elements
 * @pos: integer position
 */

void count_sort(int *array, int n, int pos)
{
	int i, freq[range] = {0};
	int *output = (int *)malloc(n * sizeof(int));

	for (i = 0; i < n; i++)
		freq[(array[i] / pos) % range]++;

	for (i = 1; i < range; i++)
		freq[i] += freq[i - 1];

	for (i = n - 1; i >= 0; i--)
	{
		output[freq[(array[i] / pos) % range] - 1] = array[i];
		freq[(array[i] / pos) % range]--;
	}

	for (i = 0; i < n; i++)
		array[i] = output[i];
	free(output);
}

/**
 * radix_sort - array of int, ascending, LSD Radix sort
 * @array: input integers
 * @size: size or array
 */

void radix_sort(int *array, size_t size)
{
	int mul = 1, m = max(array, size);

	while (m)
	{
		count_sort(array, size, mul);
		mul *= 10;
		m /= 10;
		print_array(array, size);
	}
}
