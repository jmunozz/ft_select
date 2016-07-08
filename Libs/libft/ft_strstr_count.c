/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr_count.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmunoz <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/09 19:25:03 by jmunoz            #+#    #+#             */
/*   Updated: 2016/05/09 20:05:09 by jmunoz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int		ft_strstr_count(char *big, char *little)
{
	int i;
	int j;
	int nb;

	nb = 0;
	i = 0;
	while (big[i])
	{
		j = 0;
		if (big[i] == little[j])
		{
			while ((big[i] == little[j]) && little[j])
			{	
				i++;
				j++;
			}
			if (!little[j])
				nb++;
			i = i - j;
		}
		i++;
	}
	return (nb);
}
