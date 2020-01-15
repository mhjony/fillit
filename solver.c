/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ismelich <ismelich@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/28 10:48:22 by ismelich          #+#    #+#             */
/*   Updated: 2019/12/04 11:41:25 by ismelich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		insert_tetra_row(char **row, char **tetra, int x, int y)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (tetra[i] != 0)
	{
		while (tetra[i][j] != 0)
		{
			if (tetra[i][j] != '.')
			{
				row[x + i][y + j] = tetra[i][j];
			}
			j++;
		}
		j = 0;
		i++;
	}
	return (0);
}

/*
** Here we are cleaning the not needed '.'.
** The output will stay always as a square.
*/

int		clean_tetra_row(char **row, char **tetra, int x, int y)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (tetra[i] != 0)
	{
		while (tetra[i][j] != 0)
		{
			if (tetra[i][j] != '.')
			{
				row[x + i][y + j] = '.';
			}
			j++;
		}
		j = 0;
		i++;
	}
	return (0);
}

/*
** Here we check where we can fit our tetra, if there would be a . or
** the 0, the fitting would not be possibe.
*/

int		insert_checker(char **row, char **tetra, int x, int y)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (tetra[i] != 0)
	{
		if (row[x + i] == 0)
			return (0);
		while (tetra[i][j] != 0)
		{
			if (row[x + i][y + j] == 0)
				return (0);
			if (tetra[i][j] != '.' && row[x + i][y + j] != '.')
			{
				return (0);
			}
			j++;
		}
		j = 0;
		i++;
	}
	return (1);
}

/*
** Here the magic happens, we backtrack through rows and columns
** and try to fit the tetras on the top left of our square, and
** in the meantime, we look for the best solving method.
*/

int		backtracking(char **row, char ***tetra, int b)
{
	int i;
	int j;

	i = 0;
	j = 0;
	if (tetra[b] == 0)
		return (0);
	while (row[i] != 0)
	{
		while (row[i][j] != 0)
		{
			if (insert_checker(row, tetra[b], i, j))
			{
				insert_tetra_row(row, tetra[b], i, j);
				if (!backtracking(row, tetra, b + 1))
					return (0);
				clean_tetra_row(row, tetra[b], i, j);
			}
			j++;
		}
		i++;
		j = 0;
	}
	return (1);
}

/*
** If our squar is to small to handle the tetras, we increase the
** min_size and generat and new row, until we can fit our tetras.
*/

int		solve(char ***tetra)
{
	int		min_size;
	char	**row;

	min_size = ft_floor_sqrt(num_tetra(tetra) * 4);
	row = gen_row(min_size, min_size, '.');
	while (backtracking(row, tetra, 0))
	{
		min_size++;
		free_row(row);
		row = gen_row(min_size, min_size, '.');
	}
	print_row(row);
	free_row(row);
	return (0);
}
