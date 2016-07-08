/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnjoin.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmunoz <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/01 11:18:17 by jmunoz            #+#    #+#             */
/*   Updated: 2016/04/01 11:44:57 by jmunoz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnjoin(char const *s1, char const *s2, size_t size)
{
	char *s3;

	s3 = NULL;
	if (s1 && s2)
	{
		s3 = ft_strnew(ft_strlen(s1) + size);
		if (!s3)
			return (NULL);
		s3 = ft_strcpy(s3, s1);
		s3 = ft_strncat(s3, s2, size);
	}
	return (s3);
}
