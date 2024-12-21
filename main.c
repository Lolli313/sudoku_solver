#include <stdio.h>
#include <stdlib.h>

int	isSafe(int matrix[9][9], int row, int column, int nbr)
{
	int	i = 0;
	int	temp = 0;

	while (i < 9)
	{
		if (nbr == matrix[row][i])
			return (0);
		i++;
	}
	i = 0;
	while (i < 9)
	{
		if (nbr == matrix[i][column])
			return (0);
		i++;
	}
	row = row - (row % 3);
	column = column - (column % 3);
	while (temp < 9)
	{
		if (temp % 3 == 0 && temp != 0)
		{
			column -= 3;
			row++;
		}
		if (matrix[row][column] == nbr)
			return (0);
		column++;
		temp++;
	}
	return (1);
}

int	solveMatrix(int matrix[9][9], int row, int column)
{
	static int	nbr = 1;

	while (row <= 8)
	{
		
		if (isSafe(matrix, row, column, nbr) == 1)
			matrix[row][column] = nbr;
		else
		{
			nbr++;
			return (solveMatrix(matrix, row, column));
		}
		if (nbr >= 9)
			nbr = 1;
		if (column == 8)
			return (solveMatrix(matrix, row + 1, 0));
		else
			return (solveMatrix(matrix, row, column + 1));
	}
	return (1);
}

void	printMatrix(int matrix[9][9])
{
	for (int row = 0; row < 9; row++)
	{
		for (int column = 0; column < 9; column++)
			printf("%d ", matrix[row][column]);
		printf("\n");
	}	
}

int	main(void)
{
	/*int	matrix[9][9] = {
		{0, 0, 7, 0, 0, 1, 0, 0, 0},
		{0, 8, 0, 6, 9, 0, 2, 0, 1},
		{0, 6, 0, 3, 5, 8, 7, 0, 9},
		{3, 0, 5, 0, 1, 6, 0, 0, 0},
		{0, 0, 0, 4, 0, 2, 0, 0, 0},
		{0, 0, 0, 5, 7, 0, 6, 0, 3},
		{1, 0, 4, 9, 6, 3, 0, 7, 0},
		{5, 0, 9, 0, 8, 4, 0, 6, 0},
		{0, 0, 0, 1, 0, 0, 3, 0, 0}
	};*/
	int	matrix[9][9] = {
		{0, 0, 0, 0, 0, 0, 0, 0, 0},
		{0, 0, 0, 0, 0, 0, 0, 0, 0},
		{0, 0, 0, 0, 0, 0, 0, 0, 0},
		{0, 0, 0, 0, 0, 0, 0, 0, 0},
		{0, 0, 0, 0, 0, 0, 0, 0, 0},
		{0, 0, 0, 0, 0, 0, 0, 0, 0},
		{0, 0, 0, 0, 0, 0, 0, 0, 0},
		{0, 0, 0, 0, 0, 0, 0, 0, 0},
		{0, 0, 0, 0, 0, 0, 0, 0, 0}
	};
	solveMatrix(matrix, 0, 0);
	printMatrix(matrix);
	return 0;
}
