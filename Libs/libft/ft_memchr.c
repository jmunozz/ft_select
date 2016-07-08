/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmunoz <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/03 10:58:56 by jmunoz            #+#    #+#             */
/*   Updated: 2016/03/06 16:37:29 by jmunoz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char *s_temp;
	unsigned char c_temp;

	s_temp = (unsigned char*)s;
	c_temp = (unsigned char)c;
	while (n--)
	{
		if (*(s_temp) == c_temp)
			return ((void*)s_temp);
		s_temp++;
	}
	return (NULL);
}
