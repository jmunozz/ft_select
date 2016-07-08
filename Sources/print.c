#include "../Includes/ft_select.h"

int		fputchar(int c)
{
	write(1, &c, 1);
	return (c);
}

void			init_screen(void)
{
	tputs(tgetstr("cl", NULL), 1, &fputchar);
	tputs(tgetstr("vi", NULL), 1, &fputchar);
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

void			print(t_meta *meta, t_list *begin)
{
	t_list		*tmp;

	save_pos(meta, 0);
	init_pos(meta, "hl");
	tmp = begin;
	init_screen();
	while (tmp && POS_L + COL_PAD[CUR_COL] < L)
	{
		tputs(tgoto(tgetstr("cm", NULL), POS_L, POS_H), 1, &fputchar);
		print_elem(meta, tmp, tmp->content, 1);
		POS_H++;
		if (POS_H == H)
		{
			POS_H = 0;
			POS_L += COL_PAD[CUR_COL++] + SPACING;
		}
		tmp = tmp->next;
	}
	COL_PR = (tmp) ? CUR_COL : 666;
	save_pos(meta, 1);
}
