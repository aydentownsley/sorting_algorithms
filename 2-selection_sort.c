#include "sort.h"
#include <stdlib.h>

/**
 *
 *
 *
 *
 *
 *
 */

void selection_sort(int *array, size_t size)
{
	int swap, min = 0;
	long unsigned int min_pos = 0, idx = 0, min_p = 1, loops = 0;
	
	while (loops < size)
	{
		min = array[min_p - 1];
		for (idx = min_p; idx < size; idx++)
		{
			if (min > array[idx])
			{
				min = array[idx];
				min_pos = idx;
			}

			if (idx == size - 1)
			{
				swap = array[min_p - 1];
				array[min_p - 1] = min;
				array[min_pos] = swap;
				print_array(array, size);
			}
		}
		min_p++;
		loops++;
	}
}