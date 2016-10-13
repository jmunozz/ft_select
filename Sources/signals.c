#include "../Includes/ft_select.h"

void	sigtstp(t_meta *meta, int sig)
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
		exit_select(meta);

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

void	handle_sig(int sig)
{
	t_meta		*meta;
	t_winsize	win;

	meta = get_meta(NULL);
	if (sig == SIGINT || sig ==  SIGQUIT || sig == SIGTERM)
	{
		handle_term(1);
		tputs(tgetstr("ve", NULL), 1, &fputchar);
		exit_select(meta);
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

void	set_signals()
{
	signal(SIGINT, &handle_sig);
	signal(SIGQUIT, &handle_sig);
	signal(SIGTERM, &handle_sig);
	signal(SIGWINCH, &handle_sig);
	signal(SIGTSTP, &handle_sig);
	signal(SIGCONT, &handle_sig);
}
