#include <stdio.h>
#include <stdlib.h>

/**
 * largestRange - returns an array of length 2, which contains the largest
 * range in an array
 * @array: the integer array to work on
 *
 * Description: the first element of the returned array is the first number
 * and the second element is the second number which make up the largest
 * range
 *
 * Return: a 2-element array.
 * or NULL if array is NULL
 */
int *largestRange(int *array)
{
	static int range[2] = {0, 0};
	int len = 0;
	int arr_size = sizeof(array);
	int a = 0, b = 0;

	if ((!array) || (arr_size == 1))
	{
		return (NULL);
	}
	if (arr_size == 2)
	{
		return (array);
	}

	range[0] = array[0];
	range[1] = array[1];
	len = abs(array[1] - array[0]);

	for (a = 0; a < arr_size; a++)
	{
		for (b = a + 1; b < arr_size; b++)
		{
			if (abs(array[b] - array[a]) > len)
			{
				len = abs(array[b] - array[a]);
				range[0] = array[a];
				range[1] = array[b];
			}
		}
	}

	return (range);
}
