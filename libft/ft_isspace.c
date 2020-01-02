/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isspace.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ismelich <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/21 14:23:10 by ismelich          #+#    #+#             */
/*   Updated: 2019/10/31 18:46:05 by ismelich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Checks wheter the passed char is white-space '\t' - horizontal tab
** '\n'-newline, '\v'-vertical tab, '\f'-feed, '\r'-carriage return
*/

int	ft_isspace(int c)
{
	return (c == '\t' || c == '\n' || c == '\v' || c == '\f' || c == '\r' ||
			c == ' ');
}
