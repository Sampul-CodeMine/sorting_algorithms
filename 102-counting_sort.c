#include "sort.h"

int get_maximum(int *, int);

/**
 * counting_sort - function- sort array in ascending order using Counting sort
 * @array: the array to sort
 * @size: the size of the array to sort
 * Return: Nothing
 */

void counting_sort(int *array, size_t size)
{
	int large = 0, itr = 0;
	int *sortptr, *counts;

	if (array == NULL || size < 2)
		return;

	sortptr = malloc(sizeof(int) * size);
	if (sortptr == NULL)
		return;

	large = get_maximum(array, size) + 1;

	counts = malloc(sizeof(int) * large);
	if (counts == NULL)
		return;

	/* Initialize count array with all zeros. */
	for (itr = 0; itr < large; itr++)
		counts[itr] = 0;

	/* Store the count of each element */
	for (itr = 0; itr < (int)size; itr++)
		counts[array[itr]]++;

	/* Store the cummulative count of each array */
	for (itr = 1; itr <= large; itr++)
		counts[itr] += counts[itr - 1];

	print_array(counts, large);

	/** Find the index of each element of the original array in count array
	 * and place the elements in output array
	 */
	for (itr = size - 1; itr >= 0; itr--)
	{
		sortptr[counts[array[itr]] - 1] = array[itr];
		counts[array[itr]]--;
	}
	for (itr = 0; itr < (int)size; itr++)
		array[itr] = sortptr[itr];
	
	free(sortptr);
	free(counts);
}

/**
 * get_maximum - function that get the largest element from an array
 * @arr: the array to traverse for the largest element
 * @length: the size of the array
 * Return: (int) the largest value from the element
 */

int get_maximum(int *arr, int length)
{
	int biggest, itr = 0;

	for (biggest = arr[0], itr = 1; itr < length; itr++)
	{
		if (arr[itr] > biggest)
			biggest = arr[itr];
	}
	return (biggest);
}
