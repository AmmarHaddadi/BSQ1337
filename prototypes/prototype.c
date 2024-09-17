#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void bsq(char **matrix, int rows, int cols)
{
	// ! put this in necessary checks
	if (rows == 0 || cols == 0)
		return;

	// Allocate memory for the DP table
	int **dp = (int **)malloc(rows * sizeof(int *));
	for (int i = 0; i < rows; i++)
	{
		dp[i] = (int *)malloc(cols * sizeof(int));
		memset(dp[i], 0, cols * sizeof(int)); // Initialize dp array to 0
	}

	int atwal_9otr = 0; // Maximum side length of the square found
	int y_bot_r = 0, x_bot_r = 0;

	// Fill the DP table
	for (int y = 0; y < rows; y++)
	{
		for (int x = 0; x < cols; x++)
		{
			if (matrix[y][x] == '1')
			{
				if (y == 0 || x == 0)
					dp[y][x] = 1;
				else
				{
					dp[y][x] = (dp[y - 1][x] < dp[y][x - 1] ? dp[y - 1][x] : dp[y][x - 1]);
					dp[y][x] = (dp[y][x] < dp[y - 1][x - 1] ? dp[y][x] : dp[y - 1][x - 1]) + 1;
				}

				if (dp[y][x] > atwal_9otr)
				{
					atwal_9otr = dp[y][x];
					y_bot_r = y;
					x_bot_r = x;
				}
			}
		}
	}

	// Replace the largest square with 'X'
	for (int y = y_bot_r - atwal_9otr + 1; y <= y_bot_r; y++)
	{
		for (int x = x_bot_r - atwal_9otr + 1; x <= x_bot_r; x++)
		{
			matrix[y][x] = 'X';  //! replace this with full_char
		}
	}

	// Free memory
	for (int r = 0; r < rows; r++)
		free(dp[r]);
	free(dp);
}

// Helper function to print the matrix
void printMatrix(char **matrix, int rows, int cols)
{
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			printf("%c", matrix[i][j]);
		}
		printf("\n");
	}
}

int main()
{
	// Define the matrix
	int rows = 6, cols = 6;
	char *matrix[] = {
		"111111",
		"101011",
		"111111",
		"111111",
		"111101",
		"011111"};

	// Allocate memory for the matrix
	char **matrix_ptr = (char **)malloc(rows * sizeof(char *));
	for (int i = 0; i < rows; i++)
	{
		matrix_ptr[i] = (char *)malloc((cols + 1) * sizeof(char)); // +1 for null terminator
		strncpy(matrix_ptr[i], matrix[i], cols);
		matrix_ptr[i][cols] = '\0'; // Null-terminate each row
	}

	printf("Original Matrix:\n");
	printMatrix(matrix_ptr, rows, cols);

	// Find and update the maximal square
	bsq(matrix_ptr, rows, cols);

	printf("\nMatrix After Maximal Square Update:\n");
	printMatrix(matrix_ptr, rows, cols);

	// Free allocated memory
	for (int i = 0; i < rows; i++)
	{
		free(matrix_ptr[i]);
	}
	free(matrix_ptr);

	return 0;
}
