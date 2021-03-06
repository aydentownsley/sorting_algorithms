#include "sort.h"
#include <stdlib.h>

/**
 * counting_sort - algorithm to count sort an array
 * @array: array to sort
 * @size: size of array to sort
 */

void counting_sort(int *array, size_t size)
{
	size_t x, t;
	int *carr, *sarr, k = 0;

	if (array == NULL || size < 2)
		return;
	for (x = 0; x < size; x++)
	{
		if (array[x] > k)
			k = array[x];
	}
	carr = malloc((k + 1) * sizeof(int));
	if (carr == NULL)
		return;
	carr[0] = 0;
	for (x = 0; x < size; x++)
		carr[array[x]] += 1;
	t = k;
	for (x = 0; x <= t; x++)
		carr[x + 1] += carr[x];
	print_array(carr, (k + 1));
	sarr = malloc(size * sizeof(int));
	if (sarr == NULL)
	{
		free(carr);
		return;
	}
	for (x = 0; x < size; x++)
	{
		sarr[carr[array[x] - 1]] = array[x];
		carr[array[x]] -= 1;
	}
	for (x = 0; x < size; x++)
		array[x] = sarr[x];
	free(carr);
	free(sarr);
}
