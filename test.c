#include <stdio.h>
#include <stdlib.h>

#define UNUSED __attribute__((unused))


int *largestRange(int *array, int arr_size);	/* PROTOTYPE FOR THE FUNCTION */
int *fetch_input(int *num);	/* PROTOTYPE FOR THE INPUT FUNCTION */



/**
 * main - to test a function
 *
 * Return: 0 if successful
 */
int main(void)
{
	UNUSED int *my_array = NULL, a = 0;
	UNUSED int *my_range = NULL, arr_size = 0;

	/* fetching input from the user */
	my_array = fetch_input(&arr_size);

	/* The line below calls the function */
	my_range = largestRange(my_array, arr_size);

	printf("sizeof(my_array) = %d\n", arr_size);

	printf("my_array = {");
	for (a = 0; a < arr_size; a++)
		printf("%d, ", my_array[a]);
	printf("}\n");

	printf("\nmy_range = largestRange(my_array)\n\n");

	printf("my_range = {");
	for (a = 0; a < 2; a++)
		printf("%d, ", my_range[a]);
	printf("}\n");

	return (0);
}


/* ADDING THE CODE FOR THE FUNCTION INTO THIS FILE */


#include <stdio.h>
#include <stdlib.h>

/**
 * largestRange - returns an array of length 2, which contains the largest
 * range in an array
 * @array: the integer array to work on
 * @arr_size: the number of elements in the array
 *
 * Description: the first element of the returned array is the first number
 * and the second element is the second number which make up the largest
 * range
 *
 * Return: a 2-element array.
 * or NULL if array is NULL
 */
int *largestRange(int *array, int arr_size)
{
	static int range[2] = {0, 0};
	int len = 0;
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


/* CODE FOR FUNCTION TO GET INPUT */

/**
 * fetch_input - receives integers from the user
 * @num: container for the num of input
 *
 * Description: Only integers allowed
 * Return: pointer to allocated space for the array of integers
 * else returns NULL if function fails
 */
int *fetch_input(int *num)
{
	int *array = NULL;
	int count = 0;

	printf("\nEnter the number of integers you want to enter: ");
	scanf("%d", num);
	if ((*num) < 1)
	{
		fscanf(stdin,\
			"Error: Invalid input. Enter a higher integer\n");
		exit(EXIT_FAILURE);
	}

	array = malloc((*num) * sizeof(int));
	if (!array)
	{
		fprintf(stdin, "Error: Insufficient space.\n");
		exit(EXIT_FAILURE);
	}
	for (count = 0; count < (*num); count++)
	{
		printf("Enter an integer: ");
		scanf("%d", &array[count]);
	}
	printf("\nEntry completed!\n\n");

	return (array);
}
