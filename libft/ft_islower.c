/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_islower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ismelich <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/31 10:31:00 by ismelich          #+#    #+#             */
/*   Updated: 2019/10/31 18:37:56 by ismelich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Checks wheter the passed char is a lowercase letter.
*/

int	ft_islower(int c)
{
	return (c >= 'a' && c <= 'z');
}
