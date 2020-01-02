/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ismelich <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/19 13:20:41 by ismelich          #+#    #+#             */
/*   Updated: 2019/11/03 11:49:57 by ismelich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** File descriptor-describes a data resource, and how that resource may be
** accessed. Standard input-0, Standart output-1, Standard error-2.
*/

void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}
