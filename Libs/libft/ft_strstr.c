/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmunoz <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/22 12:38:13 by jmunoz            #+#    #+#             */
/*   Updated: 2016/03/06 17:42:06 by jmunoz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *big, const char *little)
{
	const char *big_tmp;
	const char *little_tmp;

	if (!*little)
		return ((char*)big);
	while (*big)
	{
		little_tmp = little;
		if (*big == *little_tmp)
		{
			big_tmp = big;
			while (*big_tmp == *little_tmp && *little_tmp)
			{
				big_tmp++;
				little_tmp++;
			}
			if (!*little_tmp)
				return ((char*)big);
		}
		big++;
	}
	return (NULL);
}
