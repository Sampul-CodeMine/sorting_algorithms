#include "sort.h"

/**
 * shell_sort - function to perform shell sort on an array of integers using
 * the Knurt Sequence.
 * @array: The array containing integer elements
 * @size: The size of the array.
 * Return: Nothing
*/

void shell_sort(int *array, size_t size)
{
	size_t itr, jtr;
	size_t jump = 0;
	int temp = 0;

	if (array == NULL || size < 2)
		return;
	
	while (jump <= (size / 3))
	{
		jump = jump * 3 + 1;
	}
	while (jump > 0)
	{
		for (itr = jump; itr < size; itr++)
		{
			temp = array[itr];
			for (jtr = itr; jtr >= jump && array[jtr - jump]
			    > temp; jtr -= jump)
				array[jtr] = array[jtr - jump];
			array[jtr] = temp;
		}
		print_array(array, size);
		jump = (jump - 1) / 3;
	}
}
