/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ismelich <ismelich@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/28 10:44:44 by ismelich          #+#    #+#             */
/*   Updated: 2019/12/09 11:23:22 by ismelich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

/*
** Here we are generating a matrix and filling it with dots.
*/

char	***gen_matrix(int size, int m, int n, char c)
{
	char	***matrix;
	int		b;
	int		i;
	int		j;

	b = 0;
	i = 0;
	matrix = (char***)malloc(sizeof(char**) * (size + 1));
	while (b < size)
	{
		matrix[b] = (char**)malloc(sizeof(char*) * (m + 1));
		while (i < m)
		{
			j = 0;
			matrix[b][i] = ft_strnew(n);
			while (j < n)
				matrix[b][i][j++] = c;
			i++;
		}
		matrix[b][i] = NULL;
		b++;
		i = 0;
	}
	matrix[b] = NULL;
	return (matrix);
}

/*
** Here we are converting the # to letters and putting the letters
** into the matrix from the str.
*/

int		fill_matrix(char ***matrix, char **str)
{
	int b;
	int i;
	int j;

	b = 0;
	i = 0;
	j = 0;
	while (matrix[b] != 0)
	{
		while (matrix[b][i] != 0)
		{
			while (matrix[b][i][j] != 0)
			{
				if (str[b][i * 5 + j++] == '#')
					matrix[b][i][j - 1] = str[b][i * 5 + j - 1] + 30 + b;
			}
			i++;
			j = 0;
		}
		b++;
		i = 0;
	}
	return (0);
}

/*
** We clean the the rows in the matrix, that only have .... rows.
*/

int		clean_row_matrix(char ***matrix)
{
	int b;
	int i;
	int i2;

	b = 0;
	i = 0;
	while (matrix[b] != 0)
	{
		while (matrix[b][i] != 0)
		{
			if (!ft_strcmp(matrix[b][i], "...."))
			{
				free(matrix[b][i]);
				i2 = i--;
				while (matrix[b][i2++] != 0)
					matrix[b][i2 - 1] = matrix[b][i2];
			}
			i++;
		}
		i = 0;
		b++;
	}
	return (0);
}

/*
** Here we clean just the single dots inside our blocks, so that in the end
** just the tetra with our letters would be left.
*/

int		clean_single_column(char ***matrix, int b, int i, int j)
{
	int j2;

	j2 = 0;
	while (matrix[b][i] != 0)
	{
		if (matrix[b][i][j] == '.')
			j2++;
		i++;
	}
	if (j2 == i)
	{
		i = 0;
		while (matrix[b][i] != 0)
		{
			j2 = j;
			while (matrix[b][i][j2] != 0)
			{
				matrix[b][i][j2] = matrix[b][i][j2 + 1];
				j2++;
			}
			i++;
		}
		j--;
	}
	return (j);
}

int		clean_column_matrix(char ***matrix)
{
	int b;
	int i;
	int j;

	b = 0;
	i = 0;
	j = 0;
	while (matrix[b] != 0)
	{
		while (matrix[b][i][j] != 0)
		{
			j = clean_single_column(matrix, b, i, j);
			j++;
		}
		b++;
		j = 0;
	}
	return (0);
}
