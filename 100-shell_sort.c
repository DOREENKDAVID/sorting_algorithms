#include "sort.h"

/**
 * shell_sort - function that sorts an array of integers in ascending
 * order using the Shell sort algorithm, using the Knuth sequence
 * @array: array to be sorted
 * @size: size of array
 * Description:
 * Calculate the initial gap size using the sequence (gap * 3) + 1
 * Start the shell sort algorithm
 * Perform insertion sort-like comparisons within the subarrays
 *  Place the current element in its sorted position within the subarray
 * Print the array after each step
 * reduce the gap size for next iteration
*/
void shell_sort(int *array, size_t size)
{
	size_t i, j;
	int temp;
	size_t gap = 1;

	for (gap = (gap * 3) + 1; gap > 0; gap = gap / 3)
	{
		for (j = gap; j < size; j++)
		{
			temp = array[j];
			i = j;

		while (i >= gap && array[i - gap] > temp)
		{
			array[i] = array[i - gap];
			i -= gap;

		}
		array[i] = temp;
		}
	print_array(array, size);

	}
}
