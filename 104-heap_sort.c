#include "sort.h"

/**
 * swap - swaps position of values in array
 * @array: array to be sorted
 * @largest: index
 * @i: index
 *
 * Return: nothing
 */
void swap(int *array, int largest, int i)
{
	int temp;

	temp = array[largest];
	array[largest] = array[i];
	array[i] = temp;
}
/**
 * build_Max_Heap - func builds a heap from an array
 * @array: array to be changed to heap array
 *  * @i: starting point index as array is sorted
 * @size: array size
 *
 * Return: nothing
 */
void build_Max_Heap(int *array, size_t i, size_t size)
{
	size_t largest, left, right;

	largest = i;
	left = (i * 2);
	right = (i * 2) + 1;

	if (left < size && array[left] > array[largest])
		largest = left;

	if (right < size && array[right] > array[largest])
		largest = right;

	if (largest != i)
	{
		swap(array, i, largest);
		/*print_array(array, size);*/
		build_Max_Heap(array, largest, size);
	}
}
/**
 * heap_sort - function sorts an array using the Heap sort algorithm
 * @array: array to be sorted
 * @size: size of the array
 *
 * Return: nothing
 */
void heap_sort(int *array, size_t size)
{
	int largest_index, i;

	if (!array || size < 2)
		return;

	largest_index = (size - 1) / 2;

	/*Build max heap*/
	for (i = largest_index; i >= 0; i--)
	{
		build_Max_Heap(array, i, size);
	}

	/*Delete max heap and print sorted array*/
	for (i = size - 1; i > 0; i--)
	{
		swap(array, 0, i);
		print_array(array, size);
		build_Max_Heap(array, 0, i);
	}
}
