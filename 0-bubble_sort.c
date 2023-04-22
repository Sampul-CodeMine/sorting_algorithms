#include "sort.h"

void swapper(int *, int *);

/**
 * bubble_sort - This is a function that sorts an array of integers in
 * ascending order
 *
 */

void bubble_sort(int *array, size_t size)
{
	size_t f_itr = 0;
	size_t s_itr = 0;
	bool flag;

	if (array == NULL || size < 2)
		return;
	for (f_itr = 0; f_itr < (size - 1); f_itr++)
	{
		flag = false;
		for (s_itr = 0; s_itr < (size - f_itr - 1); s_itr++)
		{
			if (array[s_itr] > array[s_itr + 1])
			{
				swapper(&array[s_itr], &array[s_itr + 1]);
				flag = true;
				print_array(array, size);
			}
		}
		if (flag == false)
			break;
	}
}

/**
 * swap - swap array elements
 * @val_a_ptr: ptr to array element
 * @val_b_ptr: prt to array element
 */
    void swapper(int *val_a_ptr, int *val_b_ptr)
{
	int temp;

	temp = *val_a_ptr;
	*val_a_ptr = *val_b_ptr;
	*val_b_ptr = temp;
}
