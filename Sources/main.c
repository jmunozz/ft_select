#include "../Includes/ft_select.h"

void	handle_term(char c)
{
	t_termios			term;
	static t_termios	*save;

	if (c == 0)
	{
		if (tcgetattr(0, &term) == -1)
			ft_errors();
		save = (t_termios*)ft_memalloc(sizeof(t_termios));
		save = ft_memcpy(save, &term, sizeof(t_termios));
		term.c_lflag &= ~(ICANON);
		term.c_lflag &= ~(ECHO);
		if (tcsetattr(0, TCSADRAIN, &term) == -1)
			ft_errors();
	}
	if (c == 1 && save)
	{
		if (tcsetattr(0, TCSADRAIN, save) == -1)
			ft_errors();
		free(save);
	}
}

char	**return_select(t_meta *meta)
{
	t_list		*tmp;
	t_ushort	size;
	char		**tab;

	tmp = BEGIN;
	size = 0;
	while (tmp)
	{
		if (tmp->content_size & 1)
			size++;
		tmp = tmp->next;
	}
	tab = (char**)malloc(sizeof(char*) * size  + 1);
	tab[size] = NULL;
	tmp = BEGIN;
	size = 0;
	while (tmp)
	{
		if (tmp->content_size & 1)
			tab[size++] = ft_strdup(tmp->content);
		tmp = tmp->next;
	}
	return (tab);
}

void	read_keys(t_meta *meta)
{
	int		i;
	char	buf[4];

	i = 1;
	while (i == 1)
	{
		ft_memset(buf, '\0', 4);
		read(0, buf, 3);
		if (buf[0] == 27 && buf[1] == 91)
		{
			if (buf[2] == 68)
				ft_move(meta, LEFT);
			if (buf[2] == 67)
				ft_move(meta, RIGHT);
			if (buf[2] == 65)
				ft_move(meta, UP);
			if (buf[2] == 66)
				ft_move(meta, DOWN);
		}
		if (buf[0] == 32 && !buf[1])
		{
			ft_current(meta, 2);
			ft_move(meta, DOWN);
		}
		if (buf[0] == 27 && !buf[1])
			i = 2;
	}
}

void	debug(t_meta *meta)
{

	dprintf(1, "\n");
	dprintf(1, "col_nb: %d\n", COL_NB);
	dprintf(1, "cur_col: %d\n", CUR_COL);
	dprintf(1, "h: %d\n", H);
	dprintf(1, "l: %d\n", L);
	dprintf(1, "pos_h: %d\n", POS_H);
	dprintf(1, "pos_l: %d\n", POS_L);
	dprintf(1, "lst_size: %d\n", LST_SIZE);
	dprintf(1, "col_pr: %d\n", COL_PR);
	dprintf(1, "last: %d\n", LAST);
}


void	print_elems(t_list *elem)
{
	//ft_putendl(elem->content);
	dprintf(1, "%s\n", elem->content);
}

void			init_last(t_meta *meta)
{
	t_ushort i;
	t_ushort to;

	i = -1;
	to = 0;
	while (++i < COL_NB)
	{
		to += COL_PAD[i] + SPACING;
		if (to > L)
		{
			LAST = i--;
			to = 0;
		}
	}
}

int				init_pad(t_meta *meta)
{
	t_ushort	col_nb;
	t_ushort	*col_pad;
	t_list		*tmp;
	t_ushort	i;
	t_ushort	j;
	t_ushort	padmax;

	col_nb =  meta->lst_size / meta->h;
	col_nb = (meta->lst_size % meta->h) ? col_nb + 1 : col_nb;
	COL_NB = col_nb;
	dprintf(1, "col_nb: %d\n", col_nb);
	if (!(col_pad = (t_ushort*)malloc(sizeof(t_ushort) * col_nb + 1)))
		return (0);
	col_pad[col_nb] = 0;
	i = 0;
	j = -1;
	tmp = meta->begin;
	padmax = 0;
	while (tmp)
	{
		i++;
		padmax = (ft_strlen(tmp->content) > padmax) ? ft_strlen(tmp->content) : padmax;
		if (i == meta->h || tmp->next == NULL)
		{
			col_pad[++j] = padmax;
			padmax = 0;
			i = 0;
		}
		tmp = tmp->next;
	}
	meta->col_pad = col_pad;
	init_last(meta);
	return (1);
}

static int		init_term(t_meta *meta)
{
	if (tgetent(NULL, getenv("TERM")) < 0)
		return (0);
	meta->h = (t_ushort)tgetnum("li");
	meta->l = (t_ushort)tgetnum("co");
	return (1);
}

static size_t	init_data(char *str)
{
	return (0);
}

void			init_pos(t_meta *meta, char *str)
{
	if (ft_strchr(str, 'h'))
		POS_H = 0;
	if (ft_strchr(str, 'l'))
		POS_L = 0;
	if (ft_strchr(str, 'c'))
		CUR_COL = 0;
}

void			init_list(t_meta *meta, char **av)
{
	int		i;
	size_t	data;

	i = 0;
	while (av[++i])
	{
		if (!meta->begin)
			meta->begin = ft_lstcpy(av[i], init_data(av[i]));
		else
			ft_lstaddback(&(meta->begin), ft_lstcpy(av[i], init_data(av[i])));
	}
	meta->lst_size = i - 1;
}
void			exit_select(t_meta *meta)
{
	handle_term(1);
	tputs(tgetstr("ve", NULL), 1, &fputchar);
	tputs(tgetstr("cl", NULL), 1, &fputchar);
}

int				main (int ac, char **av)
{
	int		i;
	t_meta	meta;
	char	**tab;

	i =  -1;
	set_signals();
	init_list(&meta, av);
	init_term(&meta);
	init_pad(&meta);
	init_pos(&meta, "hlc");
	print(&meta, meta.begin);
	handle_term(0);
	ft_current(&meta, 0);
	read_keys(&meta);
	exit_select(&meta);
	tab = return_select(&meta);
	while (*tab)
	{
		ft_putstr(*tab);
		tab++;
	}
	debug(&meta);
	return (0);
}
