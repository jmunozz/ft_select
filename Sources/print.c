#include "../Includes/ft_select.h"

/*
** Place le curseur en 0,0.
** Efface tout l'écran.
** Initialise POS_H et POS_L à 0,0;
*/
void			init_screen(t_meta *meta)
{
	tputs(tgetstr("cl", NULL), 1, &fputchar);
	tputs(tgoto(tgetstr("cm", NULL), POS_L, POS_H), 1, &fputchar);
	init_pos(meta, "hl");
}
/*
** Sauvegarde la position de l'element.
*/
void			save_pos(t_meta *meta, char mode)
{
	static t_ushort pos_h;
	static t_ushort	pos_l;
	static t_ushort cur_col;

	if (mode == 0)
	{
		pos_h = POS_H;
		pos_l = POS_L;
		cur_col = CUR_COL;
	}
	if (mode == 1)
	{
		POS_H = pos_h;
		POS_L = pos_l;
		CUR_COL = cur_col;
	}
}
/*
**Replace le curseur au début de la colonne courante.
**Si mode 1 = efface la ligne courante après le début de la colonne.
*/
void			clear_line(t_meta *meta, char mode)
{
	tputs(tgoto(tgetstr("cm", NULL), POS_L, POS_H), 1, &fputchar);
	if (mode == 1)
		tputs(tgetstr("ce", NULL), 1, &fputchar);
}
/*
**Imprime un unique élément avec le paddig correspondant à la colonne courante
**mode 0 = souligné, mode 1 = non-souligné, content_size = 1 == surligné
*/
void			print_elem(t_meta *meta, t_list *elem, char mode)
{
	char	*print;
	int		fd;

	fd = get_fd(0);
	tputs(tgoto(tgetstr("cm", NULL), POS_L, POS_H), 1, &fputchar);
	if (elem->content_size & 1)
		tputs(tgetstr("mr", NULL), 1, &fputchar);
	if (mode == 0)
		tputs(tgetstr("us", NULL), 1, &fputchar);
	if (mode == 1)
		tputs(tgetstr("ue", NULL), 1, &fputchar);
	ft_set_color(elem->content_size);
	ft_putstr_fd((print = ft_padding_left(elem->content, ' ',
	COL_PAD[CUR_COL])), fd);
	free(print);
	if (elem->content_size & 1)
		tputs(tgetstr("me", NULL), 1, &fputchar);
	ft_set_color(0);
}
/*
**Imprime autant de colonnes que peut en contenir une page à partir de l'élement
**passé en paramètre. mode 0 = impression de la page depuis son début (impression
**initiale, déplacements); mode 1 = impression à partir du premier élément de la
**colonne courante (gère la suppression de la ligne courante avant impression)
*/
void			print(t_meta *meta, t_list *begin, char mode)
{
	t_list		*tmp;

	save_pos(meta, 0);
	if (mode == 0)
		init_screen(meta);
	if (mode == 1)
		init_pos(meta, "h");
	tmp = begin;
	while (tmp && POS_L + COL_PAD[CUR_COL] < L)
	{
		tputs(tgoto(tgetstr("cm", NULL), POS_L, POS_H), 1, &fputchar);
		clear_line(meta, mode);
		print_elem(meta, tmp, 1);
		if (++POS_H == H)
		{
			POS_H = 0;
			POS_L += COL_PAD[CUR_COL++] + SPACING;
		}
		tmp = tmp->next;
	}
	clear_line(meta, mode);
	COL_PR = (tmp) ? CUR_COL : 666;
	save_pos(meta, 1);
}
