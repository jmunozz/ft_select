/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmunoz <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/01 15:19:29 by jmunoz            #+#    #+#             */
/*   Updated: 2016/05/12 11:14:56 by jmunoz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Includes/libft.h"
#include <stdio.h>

int		main(int ac , char **av)
{
	char	**tab;
	char	**tab2;
	int		i;

	i = 0;
	tab = ft_strsplit(av[1], ' ');
	tab2 = ft_tabdup(tab);
	while (tab2 && tab2[i])
	{
		printf("%s\n", tab2[i]);
		i++;
	}
	return (0);
}	
