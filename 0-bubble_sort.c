#include "sort.h"

/**
 * bubble_sort - function that sorts an array of integers in ascending
 * order using the Bubble sort algorithm
 *
 * @array: array to be sorted
 * @size: size of the array
 */

void bubble_sort(int *array, size_t size)
{
	int temp;
	size_t i, j, flag;

	if (size < 2)
	{
		return;
	}

	for (i = 0; i < size; i++)
	{
		flag = 0;

		for (j = 0; j < (size - 1); j++)
		{
			if (array[j] > array[j + 1])
			{
				temp = array[j];
				array[j] = array[j + 1];
				array[j + 1] = temp;
				print_array(array, size);
				flag = 1;
			}

		}
	if (!flag)
	{
		break;
	}
	}

}
