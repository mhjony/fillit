/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ismelich <ismelich@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/19 12:01:16 by ismelich          #+#    #+#             */
/*   Updated: 2019/12/09 11:23:27 by ismelich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H
# include "libft.h"
# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>

int		ft_floor_sqrt(int value);
int		num_tetra(char ***tetra);
char	**gen_row(int m, int n, char c);
int		**free_row(char **row);
int		print_row(char **row);
char	***gen_matrix(int size, int m, int n, char c);
int		fill_matrix(char ***matrix, char **str);
int		clean_row_matrix(char ***matrix);
int		clean_single_column(char ***matrix, int b, int i, int j);
int		clean_column_matrix(char ***matrix);
int		input_length(char *path);
char	**input_strings(char *path, int size);
char	***error(void);
char	***set_up(char *path);
int		insert_tetra_row(char **row, char **tetra, int x, int y);
int		clean_tetra_row(char **row, char **tetra, int x, int y);
int		insert_checker(char **row, char **tetra, int x, int y);
int		backtracking(char **row, char ***tetra, int b);
int		solve(char ***matrix);
int		check_i(char *str, int *hash, int *l_and_r, int *empty);
int		verify_tetri(char *str);
int		validate_tetro(char **str, int i, int j);
int		tetro_checker(char ***str, int i, int j);

#endif
