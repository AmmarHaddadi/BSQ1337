#include <stdlib.h>
int **create_int_matrix(int rows, int cols)
{
	int **matrix = (int **)malloc(rows * sizeof(int *));
	if (matrix == NULL)
	{
		return NULL;
	}
	int i = 0;
	while (i < rows)
	{
		matrix[i] = (int *)malloc(cols * sizeof(int));
		if (!matrix[i])
			return NULL;
		i++;
	}

	return matrix;
}

char **create_char_matrix(int rows, int cols)
{
	char **matrix = (char **)malloc(rows * sizeof(char *));
	if (matrix == NULL)
	{
		return NULL;
	}
	int i = 0;
	while (i < rows)
	{
		matrix[i] = (char *)malloc(cols * sizeof(char));
		if (!matrix[i])
			return NULL;
		i++;
	}

	return matrix;
}

// #include <stdio.h>
// int matrix test
/*int main()
{
	int rows = 3;
	int cols = 4;

	// int values
	// int **matrix = create_int_matrix(rows, cols);
	// if (matrix == NULL)
	// 	return 1;

	// for (int i = 0; i < rows; i++)
	// {
	// 	for (int j = 0; j < cols; j++)
	// 	{
	// 		matrix[i][j] = i * cols + j;
	// 	}

	// Print the matrix
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			printf("%d ", matrix[i][j]);
		}
		printf("\n");
	}

	return 0;
}*/

// ascci matrix test
// int main()
// {
// 	int rows = 3;
// 	int cols = 4;

// 	// Create the matrix
// 	char **matrix = create_char_matrix(rows, cols);
// 	if (matrix == NULL)
// 	{
// 		fprintf(stderr, "Failed to allocate matrix.\n");
// 		return 1;
// 	}

// 	// Set some values in the matrix
// 	int i = 0;
// 	while (i < rows)
// 	{
// 		int j = 0;
// 		while (j < cols)
// 		{
// 			matrix[i][j] = 'A' + (i * cols + j);
// 			j++;
// 		}
// 		i++;
// 	}

// 	// Print the matrix
// 	i = 0;
// 	while (i < rows)
// 	{
// 		int j = 0;
// 		while (j < cols)
// 		{
// 			printf("%c ", matrix[i][j]);
// 			j++;
// 		}
// 		printf("\n");
// 		i++;
// 	}

// 	return 0;
// }
