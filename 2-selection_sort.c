#include "sort.h"

/**
 * selection sort - serches for min
 * and moves to front of array.
 *
 * @array: array being searched
 * @size: size of array
 *
 * Return: void
 */

void selection_sort(int *array, size_t size)
{
	int swap, min = 0;
	unsigned long int min_pos = 0, idx = 0, min_p = 1;

	if (size < 2)
		return;

	while (min_p != size)
	{
		min = array[min_p - 1];
		for (idx = min_p; idx < size; idx++)
		{
			if (min > array[idx])
			{
				min = array[idx];
				min_pos = idx;
			}

			if (idx == size - 1 && array[min_p - 1] != min)
			{
				swap = array[min_p - 1];
				array[min_p - 1] = min;
				array[min_pos] = swap;
				print_array(array, size);
			}
		}
		min_p++;
	}
}
