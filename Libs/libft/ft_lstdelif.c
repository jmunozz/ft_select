/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstremoveif.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmunoz <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/22 17:46:20 by jmunoz            #+#    #+#             */
/*   Updated: 2016/03/22 17:52:47 by jmunoz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdelif(t_list **alst, void *data_ref, int (*cmp)())
{
	t_list *current;
	t_list *last;

	last = *begin_list;
	current = last->next;
	while (*current)
		if (cmp(current->data, data_ref) == 0)
		{
			last->next = current->next;
			free(current);
			current = last->next;
		}
		else
		{
			last = current;
			current = last->next;
		}
	current = *begin_list;
	if (cmp(current->data, ata_ref) == 0)
	{
		*begin_list = current->next;
		free(current);
	}
}
