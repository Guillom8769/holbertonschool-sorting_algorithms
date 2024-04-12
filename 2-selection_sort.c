#include "sort.h"

/**
 * selection_sort - function that sorts an array of integers
 * in ascending order using the Selection sort algorithm
 *
 * @array: array to be sorted
 * @size: size of the array
 */
void selection_sort(int *array, size_t size)
{
	size_t index, index_bis, min_index;
	int temp;

	if (array == NULL || size < 2)
		return;

	for (index = 0; index < size - 1; index++)
	{
		min_index = index;
		for (index_bis = index + 1; index_bis < size; index_bis++)
		{
			if (array[index_bis] < array[min_index])
				min_index = index_bis;
		}

		if (min_index != index)
		{
			temp = array[index];
			array[index] = array[min_index];
			array[min_index] = temp;
			print_array(array, size);
		}
	}
}
