/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstrn_count.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmunoz <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/09 20:04:37 by jmunoz            #+#    #+#             */
/*   Updated: 2016/05/09 20:06:01 by jmunoz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strstrn_count(char *big, char *little, int size)
{
	int i;
	int j;
	int nb;

	nb = 0;
	i = 0;
	while (big[i] && i < size)
	{
		j = 0;
		if (big[i] == little[j])
		{
			while ((big[i] == little[j]) && little[j] && i < size)
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
