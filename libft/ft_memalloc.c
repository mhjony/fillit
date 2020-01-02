/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ismelich <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/24 12:07:10 by ismelich          #+#    #+#             */
/*   Updated: 2019/11/01 11:25:14 by ismelich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Allocates the requested memory and returns a pointer to it.
*/

void	*ft_memalloc(size_t size)
{
	void	*res;
	char	*reschar;
	size_t	i;

	i = 0;
	res = malloc(size);
	if (res == NULL)
	{
		return (NULL);
	}
	reschar = (char*)res;
	while (i < size)
	{
		reschar[i] = '\0';
		i++;
	}
	return (res);
}
