#include "sort.h"


/**
 * selection_sort - function that sorts an array of integers in ascending
 * order using the selection sort algorithm
 *
 * @array: array to be sorted
 * @size: size of the array
 */

void selection_sort(int *array, size_t size)
{

	size_t i, j, minval;
	int temp;
	int flag;

	if (size < 2)
	{
		return;
	}

	for (i = 0; i < (size - 1); i++)
	{
		flag = 0;
		minval = i;

		for (j = i + 1; j < size; j++)
		{
			if (array[j] < array[minval])
			{
				minval = j;
			}
		}

		if (minval != i)
		{
			temp = array[i];
			array[i] = array[minval];
			array[minval] = temp;

		flag = 1;
	}
	if (flag)
	{
		print_array(array, size);
	}
	}
}
