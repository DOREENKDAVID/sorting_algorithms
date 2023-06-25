#include "sort.h"


/**
 * partition - divides the array into two subarrays
 * left array less than the sorted index and a right array part higher
 *
 * @array: array to be sorted
 * @first: lower boundary
 * @last: upper boundary
 * @size: size of the array
 *
 * Return: index of sorted pivot
 */
size_t partition(int *array, size_t first, size_t last, size_t size)
{
	size_t low, high, pivot;
	int temp;

	pivot = last;
	low = first;

	for (high = low; high < last; high++)
	{
	if (array[high] <= array[pivot])
	{
		if (low != high)
		{
			temp = array[low];
			array[low] = array[high];
			array[high] = temp;
			print_array(array, size);

		}
		low += 1;
	}
	}
	if (low != high)
	{
		temp = array[low];
		array[low] = array[high];
		array[high] = temp;
		print_array(array, size);
	}

	return (low);

}

/**
 * sort - applies the quick sort algorithm to sort
 * a given array
 *
 * @array: array to be sorted
 * @first: lower boundary
 * @last: upper boundary
 * @size: size of the array
 */
void sort(int *array, size_t first, size_t last, size_t size)
{
	if (first < last && *array)
	{
		size_t pivot = partition(array, first, last, size);

		if (pivot - first > 1)
			sort(array, first, pivot - 1, size);
		if (last - pivot > 1)
			sort(array, pivot + 1, last, size);
	}

}
/**
 * quick_sort - sorts an array of integers in ascending order
 * using the QuickSort algorithm
 *
 * @array: array to be sorted
 * @size: size of the array
 */
void quick_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	sort(array, 0, size - 1, size);
}
