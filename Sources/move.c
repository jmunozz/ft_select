#include "../Includes/ft_select.h"

t_list	*get_elem(t_meta *meta, char mode)
{
	t_list		*tmp;
	t_ushort	i;

	save_pos(meta, 0);
	i = -1;
	tmp = meta->begin;
	if (mode == 1)
		POS_H = 0;
	while (++i < (meta->cur_col * meta->h + meta->pos_h) && tmp->next)
		tmp = tmp->next;
	save_pos(meta, 1);
	return (tmp);
}

void	select_elem(t_list *elem)
{
	elem->content_size ^= 1;
}

void	print_elem(t_meta *meta, t_list *elem,  char mode)
{
	char *print;

	tputs(tgoto(tgetstr("cm", NULL),
				meta->pos_l, meta->pos_h), 1, &fputchar);
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

void	ft_current(t_meta *meta, char mode)
{
	static t_list	*elem;

	if (mode == 0)
		print_elem(meta, (elem = get_elem(meta, 0)),  mode);
	if (mode == 1)
		print_elem(meta, elem, mode);
	if (mode == 2)
	{
		elem->content_size ^= 1;
		ft_current(meta, 0);
	}
}

void	move_right(t_meta *meta)
{
	if (CUR_COL == COL_PR - 1)
	{
		CUR_COL = COL_PR;
		print(meta, get_elem(meta, 1));
		POS_L = 0;
		//POS_H = (CUR_COL == COL_NB - 1 && LST_SIZE % H && POS_H >= LST_SIZE % H)
		//? LST_SIZE % H - 1 : pos_h;
	}
	else if (CUR_COL == COL_NB - 1 ||
			(CUR_COL == COL_NB - 2 && LST_SIZE % H && POS_H >= LST_SIZE % H))
	{
		init_pos(meta, "cl");
		print(meta, get_elem(meta, 1));
	}
	else
		POS_L += COL_PAD[CUR_COL++] + SPACING;
}

t_ushort	get_pos_l(t_meta *meta, t_ushort cur_col, t_ushort col_start)
{
	t_ushort pos_l;

	pos_l = 0;
	while (cur_col > col_start)
		pos_l += COL_PAD[col_start++] + SPACING;
	return(pos_l);
}

void	move_left(t_meta *meta)
{
	t_ushort	i;
	int			total;
	int			old_col;

	old_col = CUR_COL;
	if (!POS_L)
	{
		if (!CUR_COL)
		{
			CUR_COL = LAST;
			print(meta, get_elem(meta, 1));
			POS_L = (LST_SIZE % L && POS_H >= LST_SIZE % H) ? get_pos_l(
					meta, COL_NB - 2, LAST) : get_pos_l(meta, COL_NB - 1, LAST);
			CUR_COL = (LST_SIZE % L && POS_H >= LST_SIZE % H) ? COL_NB - 2 :
				COL_NB - 1;
		}
		else
		{
			total = -SPACING;
			i = 1;
			while (CUR_COL - i && total <= L)
				total += COL_PAD[CUR_COL - i++] + SPACING;
			CUR_COL = (total <= H) ? CUR_COL - i : CUR_COL - i + 2;
			print(meta, get_elem(meta, 1));
			POS_L = get_pos_l(meta, old_col - 1, CUR_COL);
			CUR_COL = old_col - 1;
		}
	}
	else
		POS_L -= COL_PAD[--CUR_COL] + SPACING;
}

void		move_down(t_meta *meta)
{
	if (CUR_COL != COL_NB - 1)
		if (POS_H == H - 1 || POS_H == LST_SIZE - 1)
		{
			POS_H = 0;
			move_right(meta);
		}
		else
			POS_H++;
	else
	{
		if (POS_H == H - 1 || POS_H == LST_SIZE % H - 1)
		{
			init_pos(meta, "hlc");
			print(meta, get_elem(meta, 1));
		}
		else
			POS_H++;
	}
}

void		move_up(t_meta *meta)
{
	if (!POS_H)
	{
		if (!CUR_COL)
		{
			POS_H = LST_SIZE % H - 1;
			move_left(meta);
		}
		else
		{
			POS_H = H - 1;
			move_left(meta);
		}
	}
	else
		POS_H--;
}

void		ft_move(t_meta *meta, char key)
{
	ft_current(meta, 1);
	if (key == RIGHT)
		move_right(meta);
	if (key == LEFT)
		move_left(meta);
	if (key == UP)
		move_up(meta);
	if (key == DOWN)
		move_down(meta);
	ft_current(meta, 0);
}
