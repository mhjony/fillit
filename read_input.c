/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_input.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ismelich <ismelich@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/28 10:42:58 by ismelich          #+#    #+#             */
/*   Updated: 2019/12/04 11:41:09 by ismelich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

/*
** Here we are checking the hash tetras, if they are valid in the map.
*/

int		check_i(char *str, int *hash, int *l_and_r, int *empty)
{
	int i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] != '\n' && str[i] != '.' && str[i] != '#')
			return (-1);
		if (str[i] == '.')
			(*empty)++;
		if (str[i] == '#')
		{
			if (i < 14 && str[i + 5] == '#')
				(*l_and_r)++;
			if (i >= 5 && str[i - 5] == '#')
				(*l_and_r)++;
			if (i >= 1 && str[i - 1] == '#')
				(*l_and_r)++;
			if (i < 19 && str[i + 1] == '#')
				(*l_and_r)++;
			(*hash)++;
		}
		i++;
	}
	return (0);
}

/*
** Checking if the map is valid.
*/

int		verify_tetri(char *str)
{
	int	hash;
	int	l_and_r;
	int	empty;

	if (str[4] != '\n' || str[9] != '\n' || str[14] != '\n' ||
			str[19] != '\n' || (str[20] != '\n' && str[20] != '\0'))
	{
		return (-1);
	}
	hash = 0;
	l_and_r = 0;
	empty = 0;
	check_i(str, &hash, &l_and_r, &empty);
	if ((empty != 12 || hash != 4) || l_and_r < 6)
	{
		return (-1);
	}
	return (1);
}

/*
** Reading our file and detecting number of tetras.
*/

int		input_length(char *path)
{
	int		fd;
	int		ret;
	char	*buf;
	int		counter;
	int		old_ret;

	counter = 0;
	fd = open(path, O_RDONLY);
	if (fd < 0)
		return (0);
	buf = ft_strnew(21);
	while ((ret = read(fd, buf, 21)))
	{
		if (verify_tetri(buf) < 0 || ret < 20)
			return (0);
		counter++;
		old_ret = ret;
	}
	if (old_ret != 20)
		return (0);
	free(buf);
	if (close(fd) == -1)
		return (0);
	return (counter);
}

/*
** We are allocating the needed space for our tetras and duplicating
** the tetras into output.
*/

char	**input_strings(char *path, int size)
{
	int		fd;
	int		ret;
	int		i;
	char	*buf;
	char	**output;

	i = 0;
	buf = ft_strnew(21);
	if (!(output = (char**)malloc(sizeof(char*) * (size + 1))))
		return (NULL);
	fd = open(path, O_RDONLY);
	if (fd == -1)
		return (NULL);
	while ((ret = read(fd, buf, 21)))
	{
		output[i] = ft_strdup(buf);
		i++;
	}
	free(buf);
	if (close(fd) == -1)
		return (NULL);
	return (output);
}

char	***set_up(char *path)
{
	int		size;
	char	***matrix;
	char	**str;
	int		i;

	i = 0;
	size = input_length(path);
	if (!size)
		return (error());
	str = input_strings(path, size);
	if (!str)
		return (error());
	matrix = gen_matrix(size, 4, 4, '.');
	if (!matrix)
		return (error());
	fill_matrix(matrix, str);
	if (tetro_checker(matrix, 0, 0) == 0)
		return (error());
	clean_row_matrix(matrix);
	clean_column_matrix(matrix);
	while (i < size)
		ft_strdel(&str[i++]);
	free(str);
	return (matrix);
}
