/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ismelich <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/19 19:26:17 by ismelich          #+#    #+#             */
/*   Updated: 2019/11/03 15:18:27 by ismelich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Searches for the first occurrence of the character c in the string
** pointed to by the argument str. str=World c=r return=rld
*/

char	*ft_strchr(const char *str, int c)
{
	char *a;

	a = (char *)str;
	while (*a != c)
	{
		if (!*a)
		{
			return (NULL);
		}
		a++;
	}
	return (a);
}
