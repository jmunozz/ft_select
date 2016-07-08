/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmunoz <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/22 15:20:20 by jmunoz            #+#    #+#             */
/*   Updated: 2016/03/08 12:23:01 by jmunoz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	unsigned char *s1_temp;
	unsigned char *s2_temp;

	s1_temp = (unsigned char*)s1;
	s2_temp = (unsigned char*)s2;
	while (n-- != 0)
	{
		if (*s1_temp != *s2_temp)
			return (*s1_temp - *s2_temp);
		if (!*s1_temp && !*s2_temp)
			return (0);
		s1_temp++;
		s2_temp++;
	}
	return (0);
}
