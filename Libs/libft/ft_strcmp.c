/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmunoz <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/22 15:10:38 by jmunoz            #+#    #+#             */
/*   Updated: 2016/03/08 09:01:40 by jmunoz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strcmp(const char *s1, const char *s2)
{
	int				i;
	unsigned char	*s1_temp;
	unsigned char	*s2_temp;

	s1_temp = (unsigned char*)s1;
	s2_temp = (unsigned char*)s2;
	i = 0;
	while (s1_temp[i] == s2_temp[i] && s1_temp[i])
		i++;
	return (s1_temp[i] - s2_temp[i]);
}
