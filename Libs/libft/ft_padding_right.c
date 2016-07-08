/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_padding_right.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmunoz <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/01 14:42:09 by jmunoz            #+#    #+#             */
/*   Updated: 2016/04/01 17:10:57 by jmunoz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char *ft_padding_right(char *str, char c, size_t size)
{
	char	*padded;
	char 	*begin_tmp;
	size_t	i;

	i = ft_strlen(str);
	padded = ft_strnew(size);
	padded = (char*)ft_memset(padded, c, size);
	begin_tmp = padded;
	padded = ft_strcpy(&padded[size - i], str);
	return (begin_tmp);
}	
