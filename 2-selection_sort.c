#include "sort.h"

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
	int init_min_val, position;
	bool swapped = false;

	if (!array || array == NULL || size < 2)
		return;

	for (steps = 0; steps < size; steps++)
	{
		position = steps;
		init_min_val = array[steps];
		for (itr = (steps + 1); itr < size; itr++)
		{
			if (array[itr] < init_min_val)
			{
				init_min_val = array[itr];
				position = itr;
				swapped = true;
			}
		}
		array[position] = array[steps];
		array[steps] = init_min_val;
		if (swapped)
		{
			print_array(array, size);
			swapped = false;
		}
	}	
}
