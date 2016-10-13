#include "../Includes/ft_select.h"
/*
** Selon la chaîne de caractère passée en paramètre "hcl",
** initialise pos hauteur, largeur et la colonne courante.
*/
void			init_pos(t_meta *meta, char *str)
{
	if (ft_strchr(str, 'h'))
		POS_H = 0;
	if (ft_strchr(str, 'l'))
		POS_L = 0;
	if (ft_strchr(str, 'c'))
		CUR_COL = 0;
}
/*
** Gere le curseur
*/
void		init_curseur(t_meta *meta, char mode)
{
	(void)meta;
	if (!mode)
	{
		tputs(tgetstr("vi", NULL), 1, &fputchar);
		tputs(tgetstr("ti", NULL), 1, &fputchar);
	}
	else
	{
		tputs(tgetstr("ve", NULL), 1, &fputchar);
		tputs(tgetstr("te", NULL), 1, &fputchar);
	}
}
/*
** Initisalise la hauteur et la largeur du terminal, si TERM
** est défini.
*/
int		init_term(t_meta *meta)
{
	if (tgetent(NULL, getenv("TERM")) < 0)
		return (0);
	meta->h = (t_ushort)tgetnum("li");
	meta->l = (t_ushort)tgetnum("co");
	return (1);
}
/* Créer un tableau dans la structure meta contenant
** le padding de chaque colonne.
*/
int				init_pad(t_meta *meta)
{
	t_list		*tmp;
	t_ushort	i;
	t_ushort	j;
	t_ushort	max;

	COL_NB = (LST_SIZE % H) ? LST_SIZE / H + 1 : LST_SIZE / H;
	if (!(COL_PAD = (t_ushort*)malloc(sizeof(t_ushort) * COL_NB + 1)))
		return (0);
	COL_PAD[COL_NB] = 0;
	i = 0;
	j = -1;
	tmp = BEGIN;
	max = 0;
	while (tmp)
	{
		i++;
		max = (ft_strlen(tmp->content) > max) ? ft_strlen(tmp->content) : max;
		if (i == meta->h || tmp->next == NULL)
		{
			COL_PAD[++j] = max;
			max = 0;
			i = 0;
		}
		tmp = tmp->next;
	}
	return (1);
}
/*
** Initialise la liste à partir des arguments contenus dans av.
** Initialise data_type à 0.
*/
void			init_list(t_meta *meta, char **av)
{
	int		i;
	size_t	data;

	i = 0;
	while (av[++i])
	{
		if (!meta->begin)
			meta->begin = ft_lstcpy(av[i], 0);
		else
			ft_lstaddback(&(meta->begin), ft_lstcpy(av[i], 0));
	}
	meta->lst_size = i - 1;
}

