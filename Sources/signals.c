#include "../Includes/ft_select.h"



void	handle_sig(int sig)
{
	t_meta *meta;

	if (sig == SIGINT || sig ==  SIGQUIT || sig == SIGTERM)
	{
		handle_term(1);
		tputs(tgetstr("ve", NULL), 1, &fputchar);
		exit (-1);
	}
	if (sig == SIGWINCH)
	{
		meta = get_meta(NULL);
		init_term(meta);
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
