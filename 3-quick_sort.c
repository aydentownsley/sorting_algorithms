#include "sort.h"

void qsrec(size_t start, size_t stop, int *array, size_t size);
/**
 * quick_sort - function to assort integers in ascending order
 * @array: array to sort
 * @size: size of array
 */

void quick_sort(int *array, size_t size)
{
	int start = 0;
	size_t stop = (size - 1);

	if (size < 2)
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

void qsrec(size_t start, size_t stop, int *array, size_t size)
{
	int tmp, flag = 0;
	size_t j, nstart, nstop, i = start;

	if (start >= stop)
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
	for (j = 0; j < (size - 1); j++)
	{
		if (array[j] > array[j + 1])
		{
			flag = 0;
			break;
		}
		flag = 1;
	}
	if (flag == 1)
		;
	else
	{
		nstart = 0;
		if (i == 0)
			nstop = i;
		else
			nstop = i - 1;
		qsrec(nstart, nstop, array, size);
		if ((i + 1) == size)
			nstart = 1;
		else
			nstart = i + 1;
		nstop = size - 1;
		qsrec(nstart, nstop, array, size);
	}
}
