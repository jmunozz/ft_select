#include "../Includes/ft_select.h"

void	handle_sig(int sig)
{
	if (sig == SIGINT || sig ==  SIGQUIT || sig == SIGTERM)
	{
		handle_term(1);
		tputs(tgetstr("ve", NULL), 1, &fputchar);
		exit (-1);
	}
}

void	set_signals()
{
	signal(SIGINT, &handle_sig);
	signal(SIGQUIT, &handle_sig);
	signal(SIGTERM, &handle_sig);
}
