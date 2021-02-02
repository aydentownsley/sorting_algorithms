#include "sort.h"

/**
 * num_pow - power function
 * @a: base
 * @b: power
 * Return: result
 */

size_t k_val(size_t b)
{
	int a = 3;

	if (b == 0)
		return (0);
	while (b > 1)
	{
		a = a * 3;
		b--;
	}

	a = (a - 1) / 2;
	return (a);
}

/**
 * shell_sort - compares elements of
 * array at intervals apart, decided
 * by the knuth sequence, and swaps
 * when appropriate
 *
 * @array: structure to be sorted
 * @size: size of array
 *
 * Return: Void
 */

void shell_sort(int *array, size_t size)
{
	size_t knuth = size, k_gap, idx, idy, s = size, swap_flag = 0;
	int tmp;

	for (k_gap = k_val(knuth); k_gap > 0; k_gap = k_val(knuth--))
	{
		swap_flag = 0;
		for (idx = k_gap; idx < s; idx++)
		{
			tmp = array[idx];

			for (idy = idx; idy >= k_gap &&
			array[idy - k_gap] > tmp; idy -= k_gap)
			{
				array[idy] = array[idy - k_gap];
				swap_flag = 1;
			}
			array[idy] = tmp;
		}
		if (swap_flag == 1)
			print_array(array, size);
	}
}
