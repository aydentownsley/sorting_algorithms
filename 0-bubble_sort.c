#include "sort.h"

/**
 * bubble_sort
 *
 * @array: data to be sorted
 * @size: size of array
 *
 * Return: void
 */

void bubble_sort(int *array, size_t size)
{
	unsigned int idx = 0, flag = 1, tmp;

	while (flag != 0)
	{
		flag = 0;
		for(idx = 0; idx < size - 1; idx++)
		{
			if (array[idx] < array[idx + 1])
				continue;
			else
			{
				tmp = array[idx];
				array[idx] = array[idx + 1];
				array[idx + 1] = tmp;
				flag = 1;
			}
			print_array(array, size);
		}
	}
}