/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_strsub.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmunoz <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/03 17:32:50 by jmunoz            #+#    #+#             */
/*   Updated: 2016/03/08 12:30:46 by jmunoz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char	*s2;

	s2 = NULL;
	if (s)
	{
		s2 = ft_strnew(len);
		if (s2 == NULL)
			return (NULL);
		s2 = ft_strncpy(s2, &(s[start]), len);
	}
	return (s2);
}
