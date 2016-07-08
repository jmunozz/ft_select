#include "Includes/libft.h"

t_list	*ft_lstcpy(void *content, size_t content_size)
{
	t_list	*elem;

	if (!(elem = (t_list*)malloc(sizeof(t_list))))
		return (NULL);
	elem->content = content;
	elem->content_size = content_size;
	elem->next = NULL;
	return (elem);
}

