/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_char_tab.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmunoz <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/19 15:08:41 by jmunoz            #+#    #+#             */
/*   Updated: 2016/04/19 15:52:01 by jmunoz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_sort_char_tab(char **tab, size_t size)
{
	size_t	i;
	size_t	j;
	char	*temp;

	if (tab)
	{
		i = -1;
		while (++i < size - 1)
		{
			j = i;
			while (++j < size)
				if (ft_strcmp(tab[i], tab[j]) > 0)
				{
					temp = tab[i];
					tab[i] = tab[j];
					tab[j] = temp;
				}
		}
	}
}
