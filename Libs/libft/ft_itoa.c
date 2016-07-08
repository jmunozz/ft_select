/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmunoz <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/04 16:21:46 by jmunoz            #+#    #+#             */
/*   Updated: 2016/03/22 18:19:22 by jmunoz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_nbrlen(int n)
{
	if (n == 0)
		return (0);
	return (1 + ft_nbrlen(n / 10));
}

static char		*ft_specials(int n)
{
	char	*str;

	str = NULL;
	if (n == 0)
	{
		if (!(str = ft_strnew(1)))
			return (NULL);
		str[0] = '0';
		return (str);
	}
	if (n == (-2147483648))
	{
		str = ft_strnew(11);
		str = ft_strcpy(str, "-2147483648");
		return (str);
	}
	else
		return (NULL);
}

char			*ft_itoa(int n)
{
	int		size;
	char	*str;

	str = NULL;
	str = ft_specials(n);
	if (!str)
	{
		size = (n < 0) ? ft_nbrlen(n) + 1 : ft_nbrlen(n);
		if (!(str = ft_strnew(size)))
			return (NULL);
		if (n < 0)
		{
			str[0] = '-';
			n = n * -1;
		}
		while (n / 10 != 0)
		{
			str[--size] = (n % 10) + '0';
			n = n / 10;
		}
		str[--size] = n + '0';
	}
	return (str);
}
