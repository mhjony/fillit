/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jony <jony@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/21 22:00:35 by jony              #+#    #+#             */
/*   Updated: 2020/01/02 22:30:55 by jony             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		main(int argc, char **argv)
{
	char ***matrix;

	if (argc != 2)
		ft_putendl("usage: ./fillit source_file");
	else
	{
		matrix = set_up(argv[1]);
		if (!matrix)
			return (1);
		solve(matrix);
	}
	return (1);
}