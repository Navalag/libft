/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agalavan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/08 16:38:39 by agalavan          #+#    #+#             */
/*   Updated: 2017/11/13 10:23:47 by agalavan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

/*
** Description: Allocate (with malloc(3)) and returns a “fresh” string ending
** with ’\0’ representing the integer n given as argument.
** Negative numbers must be supported. If the allocation fails,
** the function returns NULL.
**
** Param. #1 The integer to be transformed into a string.
**
** Return value: The string representing the integer passed as argument.
** Libc functions: malloc(3)
*/

static	int		ft_intlen(long int nb)
{
	int		len;

	len = 0;
	if (nb <= 0)
		len = 1;
	while (nb != 0)
	{
		nb /= 10;
		len++;
	}
	return (len);
}

char			*ft_itoa(int n)
{
	char		*res;
	size_t		len;
	long int	num;

	num = n;
	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	len = ft_intlen(num) + 1;
	if (!(res = (char*)malloc(sizeof(char) * len)))
		return (NULL);
	if (num == 0)
		res[0] = '0';
	if (num < 0)
	{
		res[0] = '-';
		num = -num;
	}
	res[len - 1] = '\0';
	while (num)
	{
		len--;
		res[len - 1] = (num % 10) + '0';
		num /= 10;
	}
	return (res);
}
