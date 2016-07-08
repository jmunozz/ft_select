/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ptit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmunoz <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/09 18:58:18 by jmunoz            #+#    #+#             */
/*   Updated: 2016/05/10 11:56:04 by jmunoz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_path_back(char *str, char c)
{
	char *tmp;
	char verif;

	verif = 0;
	tmp = str;
	while (*tmp)
	{
		if (*tmp == c)
			verif++;
		tmp++;
	}
	if (!verif)
		return (NULL);
	while (*tmp != c)
	{
		*tmp = '\0';
		tmp--;
	}
	*tmp = '\0';
	return (str);
}
