/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_freelst.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmunoz <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/13 18:21:23 by jmunoz            #+#    #+#             */
/*   Updated: 2016/10/13 19:06:43 by jmunoz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/libft.h"

void	ft_freelst(void* content, size_t content_size)
{
	if (content)
	{
		content_size = 0;
		content = (char*)content;
	}
}
