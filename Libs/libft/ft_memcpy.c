/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmunoz <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/24 08:11:54 by jmunoz            #+#    #+#             */
/*   Updated: 2016/03/08 09:03:32 by jmunoz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	void	*temp_dst;

	temp_dst = dst;
	while (n--)
		*(unsigned char*)dst++ = *(unsigned char*)src++;
	return (temp_dst);
}
