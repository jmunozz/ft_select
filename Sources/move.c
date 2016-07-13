#include "../Includes/ft_select.h"

/*
** Renvoie POS_L en fonction de la différence entre le numéro de la colonne
** courante et du numéro de la première colonne imprimée sur la page.
*/
t_ushort	get_pos_l(t_meta *meta, t_ushort cur_col, t_ushort col_start)
{
	t_ushort pos_l;

	pos_l = 0;
	while (cur_col > col_start)
		pos_l += COL_PAD[col_start++] + SPACING;
	return(pos_l);

}
/*
** Renvoie le numéro de la première colonne à imprimer sur la page en
** fonction du numéro de la colonne.
*/
t_ushort	getstart(t_meta *meta, t_ushort cur_col)
{
	int			total;
	int			i;
	t_ushort	start_col;


	total = -SPACING;
	i = -1;
	start_col = 0;
	while (++i <= cur_col)
	{
		total += COL_PAD[i] + SPACING;
		if (total > L - 1)
		{
			total = COL_PAD[i];
			start_col = i;
		}
	}
	return (start_col);
}


void		move_right(t_meta *meta)
{
	if (CUR_COL == COL_NB - 1 ||
			(CUR_COL == COL_NB - 2 && LST_SIZE % H && POS_H >= LST_SIZE % H))
	{
		init_pos(meta, "cl");
		print(meta, get_elem(meta, 1), 0);
	}
	else if (CUR_COL == COL_PR - 1)
	{
		CUR_COL = COL_PR;
		print(meta, get_elem(meta, 1), 0);
		POS_L = 0;
	}

	else
		POS_L += COL_PAD[CUR_COL++] + SPACING;
}

void		move_left(t_meta *meta)
{
	int			old_col;

	old_col = CUR_COL;
	if (!POS_L)
	{
		CUR_COL = (!CUR_COL) ? getstart(meta, COL_NB - 1) : getstart(meta, CUR_COL - 1);
		if (!old_col && POS_H >= LST_SIZE % H && CUR_COL == COL_NB - 1)
			CUR_COL = getstart(meta, CUR_COL - 1);
		print(meta, get_elem(meta, 1), 0);
		POS_L = get_pos_l(meta, old_col - 1, CUR_COL);
		if (!old_col)
		{
			if (LST_SIZE % L && POS_H >= LST_SIZE % H)
				POS_L = get_pos_l(meta, COL_NB - 2, CUR_COL);
			else
				POS_L = get_pos_l(meta, COL_NB - 1, CUR_COL);
		}
		CUR_COL = old_col - 1;
		if (!old_col)
			CUR_COL = (LST_SIZE % L && POS_H >= LST_SIZE % H) ?
			COL_NB - 2 : COL_NB - 1;
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
			print(meta, get_elem(meta, 1), 0);
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
			POS_H = LST_SIZE % H - 1;
		else
			POS_H = H - 1;
		move_left(meta);
	}
	else
		POS_H--;
}
/*
** Annule le soulignement. Effectue le déplacement adéquat (modification de
** POS_H, POS_L, CUR_COL et réimpression le cas échéant). Souligne le nouvel
** élément courant.
*/
void		ft_move(t_meta *meta, char *buf)
{
	ft_current(meta, 1);
	if (buf[2] == 67)
		move_right(meta);
	if (buf[2] == 68)
		move_left(meta);
	if (buf[2] == 65)
		move_up(meta);
	if (buf[2] == 66)
		move_down(meta);
	ft_current(meta, 0);
}
