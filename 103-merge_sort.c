#include "sort.h"

/**
 * merge - merges two sorted arrays into a single sorted array
 * @leftarr: the left array to merge
 * @rightarr: the right array to merge
 * @left_size: the size of the left array
 * @right_size: the size of the right array
 * @array: the sorted array to store the merged result
 */
void merge(int *leftarr, int *rightarr, size_t left_size, size_t right_size,
		int *array)
{
	size_t leftindex = 0;
	size_t rightindex = 0;
	size_t sortindex = 0;
	size_t i;

	printf("Merging...\n");
	printf("[left]: ");
	for (i = 0; i < left_size; i++)
		printf("%d ", leftarr[i]);
	printf("\n");

	printf("[right]: ");
	for (i = 0; i < right_size; i++)
		printf("%d ", rightarr[i]);
	printf("\n");

	while (leftindex < left_size && rightindex < right_size)
	{
		if (leftarr[leftindex] <= rightarr[rightindex])
		{
			array[sortindex] = leftarr[leftindex];
			leftindex++;
		}
		else
		{
			array[sortindex] = rightarr[rightindex];
			rightindex++;
		}
		sortindex++;
	}
	while (leftindex < left_size)
	{
		array[sortindex] = leftarr[leftindex];
		leftindex++;
		sortindex++;
	}
	while (rightindex < right_size)
	{
		array[sortindex] = rightarr[rightindex];
		rightindex++;
		sortindex++;
	}
	printf("[Done]: ");
	for (i = 0; i < sortindex; i++)
		printf("%d ", array[i]);
	printf("\n");
}
/**
 * merge_sort_helper - performs merge sort recursively on the array
 * @array: the array to be sorted
 * @start: the starting index of the range to sort
 * @end: the ending index of the range to sort
 * @temparr: temporary array used for merging
 */
void merge_sort_helper(int *array, size_t start, size_t end, int *temparr)
{
	size_t midindex, left_size, right_size, i;
	int *leftarr;
	int *rightarr;

	if (end - start < 2)
		return;

	midindex = start + (end - start) / 2;
	left_size = (midindex - start);
	right_size = (end - midindex);

	merge_sort_helper(array, start, midindex, temparr);
	merge_sort_helper(array, midindex, end, temparr);

	leftarr	= &temparr[start];
	rightarr = &temparr[midindex];

	for (i = 0; i < left_size; i++)
		leftarr[i] = array[start + i];

	for (i = 0; i < right_size; i++)
		rightarr[i] = array[midindex + i];

	merge(leftarr, rightarr, left_size, right_size, &array[start]);
}
/**
 * merge_sort - sorts an array of integers in ascending order using the merge sort algorithm
 * @array: the array to be sorted
 * @size: the size of the array
 */
void merge_sort(int *array, size_t size)
{
	size_t i;
	int *temparr;

	if (size < 2)
		return;

	temparr = malloc(sizeof(int) * size);

	if (temparr == NULL)
		return;

	for (i = 0; i < size; i++)
		temparr[i] = array[i];

	merge_sort_helper(array, 0, size, temparr);

	free(temparr);
}
