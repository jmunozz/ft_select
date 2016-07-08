#include "../Includes/ft_select.h"

int main(int ac, char **av)
{
	char	*buf;
	int		i;

	set_signals();
	buf = ft_strnew(10);
	handle_term(0);
	while (1)
	{
		read(0, buf, 10);
		i = -1;
		while (buf[++i])
			dprintf(1, "%d;", buf[i]);
		dprintf(1, "\n");
		ft_memset(buf, '\0', 10);
	}
	return (0);
}

