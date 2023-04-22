#include "sort.h"

void s_swap(int *, int *);

/**
 * selection_sort - algorithm to sort an array of integers.
 * This is a very slow algorithm
 * @array: array of integer elements.
 * @size: size of array
 * Return: Nothing
 */
void selection_sort(int *array, size_t size)
{
	size_t itr = 0;
	size_t steps = 0;
	size_t init_low;

	if (!array || size < 2)
		return;

	for (steps = 0; steps < (size - 1); steps++)
	{
		init_low = steps;
		for (itr = (steps + 1); itr < size; itr++)
		{
			if (array[itr] < array[init_low])
				init_low = itr;
		}
		s_swap(&array[init_low], &array[steps]);
		print_array(array, size);
	}
}

/**
 * s_swap - swap array elements
 * @val_a_ptr: ptr to array element
 * @val_b_ptr: prt to array element
 */

void s_swap(int *val_a_ptr, int *val_b_ptr)
{
	int temp;

	temp = *val_a_ptr;
	*val_a_ptr = *val_b_ptr;
	*val_b_ptr = temp;
}
