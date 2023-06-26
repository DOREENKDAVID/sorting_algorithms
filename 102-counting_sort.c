#include "sort.h"

/**
 * init_arr_zero - initializes array to 0
 *
 * @array: array to be initialized
 * @size: size of the array
 */
void init_arr_zero(int *array, int size)
{
	int i;

	for (i = 0; i < size; i++)
		array[i] = 0;
}
/**
 * get_max_num - func that gets the maximum value in an array
 *
 * @array: array to get max value from
 * @size: size of the array
 * Return: max num
 */
int get_max_num(int *array, size_t size)
{	size_t j;
	int k = array[0];

	for (j = 1; j < size; j++)
	{
		if (array[j] > k)
		{
			k = array[j];
		}
	}
	return (k);
}

/**
 * counting_sort - function that sorts an array of integers in ascending
 * order using the Counting sort algorithm
 * @array: array to be sorted
 * @size: size of array
 */

void counting_sort(int *array, size_t size)
{
	int *countarr;
	int *sortedarr;
	size_t j;

	int i;
	int k = get_max_num(array, size);

	countarr = malloc(sizeof(int) * (k + 1));
	if (countarr == NULL)
		return;
	init_arr_zero(countarr, k + 1);

	for (j = 0; j < size; j++)
	{
		countarr[array[j]]++;
	}
	for (i = 1; i < (k + 1); i++)
	{
		countarr[i] = countarr[i] + countarr[i - 1];
	}
	print_array(countarr, k + 1);
	sortedarr = malloc(sizeof(int) * size);
	if (sortedarr == NULL)
		return;
	init_arr_zero(sortedarr, size);
	for (j = (size - 1); j < size; j--)
	{
		countarr[array[j]]--;
		sortedarr[countarr[array[j]]] = array[j];

	}
	free(countarr);
	for (j = 0; j < size; j++)
	{
		array[j] = sortedarr[j];
	}

	free(sortedarr);
}
