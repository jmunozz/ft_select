#include "../Includes/ft_select.h"

/*
** Fonction d'impression speciale utilisee a la reprise d'un SIGCONT.
*/
static void		print_cont(t_meta *meta, t_list *begin, char mode)
{
	t_ushort	col_tmp;
	t_list		*first_elem;
	t_list		*tmp;

	save_pos(meta, 0);
	col_tmp = CUR_COL;
	CUR_COL = getstart(meta, CUR_COL);
	first_elem = get_elem(meta, 1);
	init_screen(meta);
	while (first_elem && POS_L + COL_PAD[CUR_COL] < L)
	{
		tputs(tgoto(tgetstr("cm", NULL), POS_L, POS_H), 1, &fputchar);
		clear_line(meta, mode);
		print_elem(meta, first_elem, 1);
		if (++POS_H == H)
		{
			POS_H = 0;
			POS_L += COL_PAD[CUR_COL++] + SPACING;
		}
		first_elem = first_elem->next;
	}
	clear_line(meta, mode);
	COL_PR = (tmp) ? CUR_COL : 666;
	save_pos(meta, 1);
	CUR_COL = col_tmp;
}
/*
** Gere les signaux SGITSTP et SIGCONT.
*/
void		sigtstp(t_meta *meta, int sig)
{
	t_termios	*save;
	char		c[2];

	if (sig == SIGTSTP)
	{
		save = handle_term(2);
		c[0] = save->c_cc[VSUSP];
		c[1] = 0;
		signal(SIGTSTP, SIG_DFL);
		ioctl(0, TIOCSTI, c);
		exit_select(meta, 1);

	}
	else
	{
		handle_term(0);
		init_curseur(meta, 0);
		debug(meta);
		print_cont(meta, meta->begin, 0);
		ft_current(meta, 0);
		signal(SIGTSTP, &handle_sig);
	}
}
/*
** Gere une sortie de programme correcte en cas de signaux.
*/
void		handle_sig(int sig)
{
	t_meta		*meta;
	t_winsize	win;

	meta = get_meta(NULL);
	if (sig == SIGINT || sig ==  SIGQUIT || sig == SIGTERM)
	{
		exit_select(meta, 0);
		exit (-1);
	}
	if (sig == SIGWINCH)
	{
		//init_term(meta);
		ioctl(0, TIOCGWINSZ, &win);
		H = win.ws_row;
		L = win.ws_col;
		init_pos(meta, "hcl");
		init_pad(meta);
		ft_current(meta, 4);
	}
	if (sig == SIGTSTP || sig == SIGCONT)
		sigtstp(meta, sig);
}
/*
** Renvoie a la fonction handle_sig en cas d'interception de signal.
*/
void		set_signals()
{
	signal(SIGINT, &handle_sig);
	signal(SIGQUIT, &handle_sig);
	signal(SIGTERM, &handle_sig);
	signal(SIGWINCH, &handle_sig);
	signal(SIGTSTP, &handle_sig);
	signal(SIGCONT, &handle_sig);
}
