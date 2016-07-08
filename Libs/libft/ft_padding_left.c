/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_padding_left.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmunoz <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/01 17:14:12 by jmunoz            #+#    #+#             */
/*   Updated: 2016/04/01 17:26:08 by jmunoz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_padding_left(char *str, char c, size_t size)
{
	char	*padded;

	padded = ft_strnew(size);
	padded = (char*)ft_memset(padded, c, size);
	padded = ft_strncpy(padded, str, ft_strlen(str));
	return (padded);
}
