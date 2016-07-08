/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmunoz <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/21 18:33:26 by jmunoz            #+#    #+#             */
/*   Updated: 2016/05/03 17:51:26 by jmunoz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

t_gnl	*find_fd(t_gnl **begin_list, int fd)
{
	if (*begin_list == NULL)
	{
		*begin_list = (t_gnl*)ft_memalloc(sizeof(t_gnl));
		(*begin_list)->fd = fd;
		return (*begin_list);
	}
	else if ((*begin_list)->next == NULL)
	{
		if ((*begin_list)->fd == fd)
			return (*begin_list);
		(*begin_list)->next = (t_gnl*)ft_memalloc(sizeof(t_gnl));
		(*begin_list)->next->fd = fd;
		return ((*begin_list)->next);
	}
	else
	{
		if ((*begin_list)->fd == fd)
			return (*begin_list);
		return (find_fd(&(*begin_list)->next, fd));
	}
	return (*begin_list);
}

int		read_again(t_gnl *gnl, char **line)
{
	int		size;
	char	*temp;

	while ((size = ft_strlenc(&BUFF[POS], '\n')) == RET - POS && RET)
	{
		temp = *line;
		*line = ft_strjoin(*line, &BUFF[POS]);
		free(temp);
		POS = 0;
		RET = read(FD, BUFF, BUFF_SIZE);
		BUFF[RET] = '\0';
	}
	return (size);
}

int		get_next_line(int fd, char **line)
{
	static t_gnl	*begin = NULL;
	t_gnl			*gnl;
	char			*temp;
	int				size;

	if (!line)
		return (-1);
	gnl = find_fd(&begin, fd);
	*line = ft_strnew(0);
	if (!POS || (POS == RET))
	{
		POS = 0;
		if ((RET = read(fd, BUFF, BUFF_SIZE)) <= 0)
			return (RET);
		BUFF[RET] = '\0';
	}
	size = read_again(gnl, line);
	temp = *line;
	*line = ft_strnjoin(*line, &BUFF[POS], (size_t)size);
	free(temp);
	POS = (RET == BUFF_SIZE || size < RET) ? POS + size + 1 : 0;
	return (1);
}
