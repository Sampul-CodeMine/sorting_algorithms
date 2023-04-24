#include "sort.h"

void q_swap(int *, int *);
int partitioner(int *, size_t, int, int);

/**
 * quick_sort - a function that sorts an array of integer.
 * @array: the array of integer elements to sort.
 * @size: the size of the array of integers.
 * Return: Nothing
 */

void quick_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;
	sorter(array, size, 0, size -1);	
}

/**
 * partitioner - function to partition an array into halves
 * @arr: the array to partition
 * @size: the size of the array
 * @lo_range: specify the lower range for the first array half
 * @hi_range: specift the higher range for the array half
 * Return: integer value for the iterator
 */

int partitioner(int *arr, size_t size, int lo_range, int hi_range)
{
	int *pivot, itr, jtr;

	pivot = arr + hi_range;
	for (itr = jtr = lo_range; jtr < hi_range; jtr++)
	{
		if (arr[jtr] < *pivot)
		{
			if (itr < jtr)
			{
				q_swap(arr + jtr, arr + itr);
				print_array(arr, size);
			}
			itr++;
		}
	}
	if (arr[itr] > *pivot)
	{
		q_swap(arr + itr, pivot);
		print_array(arr, size);
	}
	return (itr);	
}

/**
 * sorter - function to sort each partition
 * @arr: the array to partition
 * @size: the size of the array
 * @lo_range: specify the lowest range for the first array half
 * @hi_range: specift the highest range for the array half
 * Return: integer value for the iterator
 */

void sorter(int *arr, size_t size, int lo_range, int hi_range)
{
	int part;
	if (hi_range - lo_range > 0)
	{
		part = partitioner(arr, size, lo_range, hi_range);
		sorter(arr, size, lo_range, part - 1);
		sorter(arr, size, part + 1, hi_range);
	}
}

/**
 * q_swap - swap array elements
 * @val_a_ptr: ptr to array element
 * @val_b_ptr: prt to array element
 */

void q_swap(int *val_a_ptr, int *val_b_ptr)
{
	int temp;

	temp = *val_a_ptr;
	*val_a_ptr = *val_b_ptr;
	*val_b_ptr = temp;
}
