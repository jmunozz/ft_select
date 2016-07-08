/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_last_separators.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmunoz <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/14 15:49:49 by jmunoz            #+#    #+#             */
/*   Updated: 2016/04/14 16:13:30 by jmunoz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_last_separators(char *str, char c)
{
	int i;
	char *ret;

	i = 0;
	if (!str || !*str)
		return (NULL);
	while (str[i])
		i++;
	if (str[--i] == c)
		str[i] = '\0';
	if ((ret = ft_strrchr(str, c)))
		return (ret + 1);
	return (NULL);
}
