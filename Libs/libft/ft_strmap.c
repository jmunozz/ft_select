/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmunoz <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/03 16:45:04 by jmunoz            #+#    #+#             */
/*   Updated: 2016/03/06 15:44:55 by jmunoz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	char	*s2;
	int		i;

	s2 = NULL;
	i = 0;
	if (s && f)
	{
		s2 = ft_strnew(ft_strlen(s));
		if (!s2)
			return (NULL);
		while (s[i])
		{
			s2[i] = f(s[i]);
			i++;
		}
	}
	return (s2);
}
