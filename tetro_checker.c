/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tetro_checker.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ismelich <ismelich@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/28 10:46:32 by ismelich          #+#    #+#             */
/*   Updated: 2019/12/04 11:15:42 by ismelich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		validate_tetro(char **str, int i, int j)
{
	int		k;

	k = 0;
	if (j < 3)
	{
		if (str[i][j + 1] == str[i][j])
			k++;
	}
	if (i < 3)
	{
		if (str[i + 1][j] == str[i][j])
			k++;
	}
	if (j > 0)
	{
		if (str[i][j - 1] == str[i][j])
			k++;
	}
	if (i > 0)
	{
		if (str[i - 1][j] == str[i][j])
			k++;
	}
	return (k);
}

/*
** We check if the tetras (4 blocks) have 6 k=connections, at least.
** Squar tetra will have more.
*/

int		tetro_checker(char ***str, int i, int j)
{
	int		b;
	int		k;

	b = 0;
	k = 0;
	while (str[b] != 0)
	{
		while (str[b][i] != 0)
		{
			while (str[b][i][j] != 0)
			{
				if (str[b][i][j] >= 65 && str[b][i][j] <= 90)
					k += validate_tetro(str[b], i, j);
				j++;
			}
			j = 0;
			i++;
		}
		if (k < 6)
			return (0);
		k = 0;
		i = 0;
		b++;
	}
	return (1);
}
