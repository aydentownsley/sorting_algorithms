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

	for (x = 0; x < size; x++)
	{
		if (array[x] > k)
			k = array[x];
	}
	carr = malloc((k + 1) * 4);
	if (carr == NULL)
		return;
	for (x = 0; x < size; x++)
		carr[array[x]] += 1;
	x = 1;
	t = k;
	for (x = 1; x <= t; x++)
		carr[x] += carr[x - 1];
	print_array(carr, (k + 1));
	sarr = malloc(size * 4);
	if (sarr == NULL)
	{
		free(carr);
		return;
	}
	for (x = 0; x < size; x++)
	{
		sarr[carr[array[x]]] = array[x];
		carr[array[x]] -= 1;
	}
	print_array(sarr, size);
	for (x = 0; x < size; x++)
		array[x] = sarr[x];
	free(carr);
	free(sarr);
}
