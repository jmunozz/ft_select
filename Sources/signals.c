#include "../Includes/ft_select.h"



void	handle_sig(int sig)
{
	t_meta		*meta;
	t_winsize	win;

	if (sig == SIGINT || sig ==  SIGQUIT || sig == SIGTERM)
	{
		handle_term(1);
		tputs(tgetstr("ve", NULL), 1, &fputchar);
		exit (-1);
	}
	if (sig == SIGWINCH)
	{
		meta = get_meta(NULL);
		//init_term(meta);
		ioctl(0, TIOCGWINSZ, &win);
		H = win.ws_row;
		L = win.ws_col;
		init_pos(meta, "hcl");
		init_pad(meta);
		ft_current(meta, 4);
	}
}

void	set_signals()
{
	signal(SIGINT, &handle_sig);
	signal(SIGQUIT, &handle_sig);
	signal(SIGTERM, &handle_sig);
	signal(SIGWINCH, &handle_sig);
}
