/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmunoz <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/22 12:27:23 by jmunoz            #+#    #+#             */
/*   Updated: 2016/03/06 17:13:56 by jmunoz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char *last;
	char c_char;

	c_char = (char)c;
	last = NULL;
	while (*s)
	{
		if (*s == c)
			last = (char*)s;
		s++;
	}
	if (*s == c)
		last = (char*)s;
	return (last);
}
