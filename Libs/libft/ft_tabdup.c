/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tabdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmunoz <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/10 17:50:02 by jmunoz            #+#    #+#             */
/*   Updated: 2016/05/13 16:43:27 by jmunoz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Includes/libft.h"

char	**ft_tabdup(char **tab)
{
	char	**new_tab;
	int		size;
	int		i;

	i = -1;
	new_tab = NULL;
	if (tab && *tab)
	{
		size = ft_size_tab(tab);
		new_tab = (char**)malloc(sizeof(char*) * size);
		while (++i < size - 1)
			new_tab[i] = ft_strdup(tab[i]);
		new_tab[i] = NULL;
	}
	return (new_tab);
}
