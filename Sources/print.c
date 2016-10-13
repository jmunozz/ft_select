#include "../Includes/ft_select.h"

int				fputchar(int c)
{
	write(1, &c, 1);
	return (c);
}
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
	char *print;

	tputs(tgoto(tgetstr("cm", NULL), POS_L, POS_H), 1, &fputchar);
	if (elem->content_size & 1)
		tputs(tgetstr("mr", NULL), 1, &fputchar);
	if (mode == 0)
		tputs(tgetstr("us", NULL), 1, &fputchar);
	if (mode == 1)
		tputs(tgetstr("ue", NULL), 1, &fputchar);
	ft_putstr((print = ft_padding_left(elem->content, ' ', COL_PAD[CUR_COL])));
	free(print);
	if (elem->content_size & 1)
		tputs(tgetstr("me", NULL), 1, &fputchar);
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

void		print_cont(t_meta *meta, t_list *begin, char mode)
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

