/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmunoz <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/22 18:24:41 by jmunoz            #+#    #+#             */
/*   Updated: 2016/03/25 12:00:57 by jmunoz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char		**add_tab(char **tab, int size_tab)
{
	char	**new_tab;

	if (!(new_tab = (char**)malloc(sizeof(char*) * (size_tab + 1))))
		return (0);
	new_tab[size_tab] = NULL;
	if (size_tab == 1)
		return (new_tab);
	size_tab -= 2;
	while (size_tab >= 0)
	{
		new_tab[size_tab] = tab[size_tab];
		size_tab--;
	}
	free(tab);
	return (new_tab);
}

char			**ft_strsplit(char const *s, char c)
{
	char	**tab;
	int		size;
	int		size_tab;

	if (!(tab = (char**)malloc(sizeof(char*))))
		return (NULL);
	*tab = NULL;
	size_tab = 0;
	while (*s)
	{
		while (!(size = ft_strlenc((char*)s, c)))
			s++;
		if (size == -1)
			return (tab);
		tab = add_tab(tab, ++size_tab);
		tab[size_tab - 1] = ft_strncpy(ft_strnew(size), s, size);
		s += size;
	}
	return (tab);
}
