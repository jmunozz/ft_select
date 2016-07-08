/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmunoz <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/03 15:44:53 by jmunoz            #+#    #+#             */
/*   Updated: 2016/03/03 15:53:06 by jmunoz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memalloc(size_t size)
{
	void *temp;

	if (!size)
		return (NULL);
	temp = malloc(size);
	if (!temp)
		return (NULL);
	ft_memset(temp, 0, size);
	return (temp);
}
