/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ismelich <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/21 18:48:09 by ismelich          #+#    #+#             */
/*   Updated: 2019/11/03 11:54:59 by ismelich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Outputs the string to the standard outut followed by a new line.
*/

void	ft_putendl(char	const *str)
{
	if (str)
	{
		ft_putstr(str);
		ft_putchar('\n');
	}
}
