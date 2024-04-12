#include "sort.h"

/**
 * bubble_sort - function that sorts an array of integers in ascending order
 * using the Bubble sort algorithm
 *
 * @array: array of integers to sort.
 * @size: size of the array.
 *
 */
void bubble_sort(int *array, size_t size)
{
	size_t index, unsorted_size = size;
	int tmp, swap;

	if (array == NULL || size < 2)
		return;

	while (unsorted_size)
	{
		swap = 0;
		for (index = 0; index < unsorted_size - 1; index++)
		{
			if (array[index] > array[index + 1])
			{
				tmp = array[index + 1];
				array[index + 1] = array[index];
				array[index] = tmp;
				print_array(array, size);
				swap = 1;
			}
		}
		unsorted_size--;
		if (!swap)
			break;
	}
}
