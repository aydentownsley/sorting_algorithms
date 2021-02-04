#include "sort.h"

void qsrec(int start, int stop, int *array, size_t size);
/**
 * quick_sort - function to assort integers in ascending order
 * @array: array to sort
 * @size: size of array
 */

void quick_sort(int *array, size_t size)
{
	int start = 0;
	size_t stop = (size - 1);

	if (size < 2 || array == NULL)
		return;
	qsrec(start, stop, array, size);
}

/**
 * qsrec - recursive function to sort an array
 * @start: position in array to start
 * @stop: position to stop sorting
 * @array: array to sort
 * @size: size of array
 */

void qsrec(int start, int stop, int *array, size_t size)
{
	int tmp, j, nstart, nstop, i = start;

	if (stop - start < 1)
		return;
	for (j = start; j < stop; j++)
	{
		if (array[j] < array[stop])
		{
			tmp = array[i];
			array[i] = array[j];
			array[j] = tmp;
			if (array[j] != array[i])
				print_array(array, size);
			i += 1;
		}
	}
	tmp = array[i];
	array[i] = array[stop];
	array[stop] = tmp;
	if (array[j] != array[i])
		print_array(array, size);
	nstop = i - 1;
	qsrec(start, nstop, array, size);
	nstart = i + 1;
	qsrec(nstart, stop, array, size);
}
