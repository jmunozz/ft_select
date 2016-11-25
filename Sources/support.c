/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   support.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmunoz <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/13 17:16:07 by jmunoz            #+#    #+#             */
/*   Updated: 2016/11/25 22:31:25 by jmunoz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/ft_select.h"

/*
** Fonction qui ouvre un nouveau terminal le programme va ecrire.
*/
int		open_fd(void)
{
	int		tty;
	char	*tmp;

	tmp = ttyname(STDIN_FILENO);
	if ((tty = open(tmp, O_WRONLY)) < 0)
	{
		free(tmp);
		exit (-1);
	}
	free(tmp);
	return (tty);
}
/*
 ** Fonction qui sauvegarde et restitue meta.
 */
t_meta			*get_meta(t_meta *meta)
{
	static	t_meta *save = NULL;

	if (meta)
		save = meta;
	return (save);
}
/*
** Fonction qui sauvegarde et restitue le fd du tty sur lequel le prog ecrit.
*/
int			get_fd(int fd)
{
	static int save = -1;

	if (save < 0)
	{
		save = fd;
		return (0);
	}
	else 
		return (save);
}
/*
** Fonction qui set la couleur appropriee (en fonction de la nature du fichier)
** et reset la couleur de base.
*/
void		ft_set_color(size_t content_size)
{
	static char set = 0;

	if (!set)
	{
		if (S_ISDIR(content_size))
			ft_putstr(ANSI_COLOR_CYAN);
		else if (S_ISLNK(content_size))
			ft_putstr(ANSI_COLOR_YELLOW);
		else if (S_ISREG(content_size) && 00100 & content_size)
			ft_putstr(ANSI_COLOR_GREEN);
		else if (S_ISCHR(content_size))
			ft_putstr(ANSI_COLOR_BLUE);
		else if (S_ISBLK(content_size))
			ft_putstr(ANSI_COLOR_RED);
		else if (S_ISFIFO(content_size))
			ft_putstr(ANSI_COLOR_MAGENTA);
		else if (S_ISSOCK(content_size))
			ft_putstr(ANSI_COLOR_MAGENTA);
	}
	else
		ft_putstr(ANSI_COLOR_RESET);
	set ^= 1;

}
/*
** Fonction permettant d'utiliser les termcaps.
*/
int			fputchar(int c)
{
	int fd;

	fd = get_fd(0);
	write(fd, &c, 1);
	return (c);
}
