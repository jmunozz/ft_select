/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrev.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmunoz <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/22 16:37:30 by jmunoz            #+#    #+#             */
/*   Updated: 2016/03/22 17:21:15 by jmunoz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrev(char *str)
{
	int		len;
	int		i;
	char	temp;

	if (str)
	{
		i = 0;
		len = ft_strlen(str) - 1;
		while (i < len)
		{
			temp = str[i];
			str[i] = str[len];
			str[len] = temp;
			i++;
			len--;
		}
		return (str);
	}
	return (NULL);
}
