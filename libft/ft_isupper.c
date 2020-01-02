/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ismelich <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/31 10:36:02 by ismelich          #+#    #+#             */
/*   Updated: 2019/10/31 18:50:39 by ismelich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Checks whether the passed char is uppercase letter.
*/

int	ft_isupper(int c)
{
	return (c >= 'A' && c <= 'Z');
}
