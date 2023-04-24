#include "sort.h"

/**
 * swap - swap array elements
 * @a: first element
 * @b: second element
 */

void swap(int *a, int *b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}
