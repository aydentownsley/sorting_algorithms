#include "sort.h"

/**
 * bubble_sort - sorts by comparing adjacent
 * numbers and swapping if prev is larger
 * than next.
 *
 * @array: data to be sorted
 * @size: size of array
 *
 * Return: void
 */

void bubble_sort(int *array, size_t size)
{
	unsigned int flag = 1, tmp;
	size_t idx = 0;

	if (size < 2 || array == NULL)
		return;

	while (flag != 0)
	{
		flag = 0;
		for (idx = 0; idx < size - 1; idx++)
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
