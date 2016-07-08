/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmunoz <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/03 18:18:38 by jmunoz            #+#    #+#             */
/*   Updated: 2016/03/08 08:51:04 by jmunoz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	char		*s2;
	int			i;
	int			j;

	s2 = NULL;
	if (s)
	{
		while ((*s == ' ' || *s == '\n' || *s == '\t') && *s)
			s++;
		j = ft_strlen(s);
		i = j - 1;
		while ((s[i] == ' ' || s[i] == '\n' || s[i] == '\t') && i >= 0)
		{
			j--;
			i--;
		}
		s2 = ft_strnew(j);
		if (!s2)
			return (s2);
		s2 = ft_strncpy(s2, s, j);
	}
	return (s2);
}
