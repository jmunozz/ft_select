#include "../Includes/ft_select.h"
/*
** Fonction de gestion du terminal. mode 0 = passage aux parametre de ft_select
** et stockage des anciens params dans save. mode 1 = passage au parametres
** standards.
*/
t_termios	*handle_term(char c)
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
		return (NULL);
	}
	if (c == 1 && save)
	{
		if (tcsetattr(0, TCSADRAIN, save) == -1)
			ft_errors();
		free(save);
		return (NULL);
	}
	else
		return (save);
}
/*
** Imprime seulement les elements selectionnes de la 
** liste sur la sortie standard.
*/
void	return_select(t_meta *meta)
{
	t_list		*tmp;

	tmp = BEGIN;
	while (tmp)
	{
		if (tmp->content_size & 1)
		{
			ft_putstr(tmp->content);
			ft_putchar(' ');
		}
		tmp = tmp->next;
	}
	ft_lstdel(&BEGIN, &ft_freelst);
	free(COL_PAD);
}
/*
** Lit les keys et renvoie aux fonctions concernees.
** 1. pour toutes les fleches ft_move>
** 2. pour echap ou entree, sortie de boucle avec return 0 si echap.
** 3. pour espace et supprimer ft_current.
*/
int		read_keys(t_meta *meta)
{
	int		i;
	char	buf[4];

	i = 1;
	while (i == 1)
	{
		ft_memset(buf, '\0', 4);
		read(0, buf, 3);
		if (buf[0] == 27 && buf[1] == 91 && buf[2])
				ft_move(meta, buf);
		if (buf[0] == 32 && !buf[1])
			ft_current(meta, 2);
		if (buf[0] == 10 && !buf[1])
			i = 2;
		if (buf[0] == 27 && !buf[1])
			i = 0;
		if (buf[0] == 127 && !buf[1])
			ft_current(meta, 3);
	}
	return (i);
}

void	debug(t_meta *meta)
{
	int i;

	i = -1;
	dprintf(1, "\n");
	dprintf(1, "col_nb: %d\n", COL_NB);
	dprintf(1, "cur_col: %d\n", CUR_COL);
	dprintf(1, "h: %d\n", H);
	dprintf(1, "l: %d\n", L);
	dprintf(1, "pos_h: %d\n", POS_H);
	dprintf(1, "pos_l: %d\n", POS_L);
	dprintf(1, "lst_size: %d\n", LST_SIZE);
	dprintf(1, "col_pr: %d\n", COL_PR);
	while (++i < COL_NB)
		dprintf(1, "col_pad[%d] = %d\n", i, COL_PAD[i]);
}
/*
** Gere la sortie de programme. 
** 1. Initialise le terminal. 
** 2. Efface l'ecran.
** 3. replace le curseur au point de sauvegarde avt prog.
*/
void		exit_select(t_meta *meta, int i)
{
	handle_term(1);
	tputs(tgetstr("cl", NULL), 1, &fputchar);
	init_curseur(meta, 1);
	if (!i)
	{
		ft_lstdel(&BEGIN, &ft_freelst);
		free(COL_PAD);
	}
}

int				main (int ac, char **av, char **envp)
{
	int		i;
	t_meta	meta;
	char	**tab;

	if (!av[1] || !envp || !*envp)
		return (0);
	get_fd(open_fd());
	set_signals();
	init_list(&meta, av);
	init_term(&meta);
	init_curseur(&meta, 0);
	init_pad(&meta);
	init_pos(&meta, "hlc");
	get_meta(&meta);
	print(&meta, meta.begin, 0);
	handle_term(0);
	ft_current(&meta, 0);
	i = read_keys(&meta);
	exit_select(&meta, i);
	if (i)
		return_select(&meta);
	return (0);
}
