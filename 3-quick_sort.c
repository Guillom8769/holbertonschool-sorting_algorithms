#include "sort.h"

/**
 * lomuto_partition - Partition the array using the Lomuto partition scheme.
 *
 * @array: The array to partition.
 * @start: The starting index of the partition.
 * @end: The ending index of the partition.
 * @size: The size of the array.
 *
 * Return: The final position of the pivot element.
 */
int lomuto_partition(int *array, int start, int end, int size)
{
	int pivot_value = array[end];
	int partition_index = start, current_index, temp;

	for (current_index = start; current_index < end; current_index++)
	{
		if (array[current_index] <= pivot_value)
		{
			if (partition_index != current_index)
			{
				temp = array[partition_index];
				array[partition_index] = array[current_index];
				array[current_index] = temp;
				print_array(array, size);
			}
			partition_index++;
		}
	}
	if (partition_index != end)
	{
		temp = array[partition_index];
		array[partition_index] = array[end];
		array[end] = temp;
		print_array(array, size);
	}
	return (partition_index);
}
/**
 * quick_sort_recursive - recursively sorts an array of integers
 * using the quicksort algorithm.
 * @array: array of integers to be sorted.
 * @start: starting index of the sublist to be sorted.
 * @end: ending index of the sublist to be sorted.
 * @size: size of the array
 */
void quick_sort_recursive(int *array, int start, int end, int size)
{
	int pivot;

	if (start < end)
	{
		pivot = lomuto_partition(array, start, end, size);
		quick_sort_recursive(array, start, pivot - 1, size);
		quick_sort_recursive(array, pivot + 1, end, size);
	}
}
/**
 * quick_sort - function that sorts an array of integers in ascending order
 * using the Quick sort algorithm
 * @array: array to sort
 * @size: size of array
 */
void quick_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;
	int start = 0, end = size - 1;

	quick_sort_recursive(array, start, end, size);
}
