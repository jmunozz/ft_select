/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmunoz <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/08 10:20:29 by jmunoz            #+#    #+#             */
/*   Updated: 2016/03/08 11:38:51 by jmunoz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*new_list;
	t_list	*elem;
	t_list	*modified;

	new_list = NULL;
	if (f && lst)
	{
		modified = f(lst);
		elem = ft_lstnew(modified->content, modified->content_size);
		if (!elem)
			return (NULL);
		new_list = elem;
		while (lst->next)
		{
			lst = lst->next;
			modified = f(lst);
			elem->next = ft_lstnew(modified->content, modified->content_size);
			if (!elem)
				return (NULL);
			elem = elem->next;
		}
	}
	return (new_list);
}
