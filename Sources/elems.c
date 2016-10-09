#include "../Includes/ft_select.h"
/*
** Renvoie 1 si la largeur de la fenetre est plus grande que le plus grand
** padding. O autrement.
*/
static t_ushort	select_is_printable(t_meta *meta)
{
	int i;

	i = -1;
	while (COL_PAD[++i])
		if (COL_PAD[i] > L)
			return (0);
	return (1);
}
/*
**  le numero de la colonne dans laquelle
** se trouve l'element.
*/
void	set_pos(t_meta *meta, t_list *elem)
{
	t_list *tmp;

	init_pos(meta, "clh");
	tmp = BEGIN;
	while (tmp != elem)
	{
		if (++POS_H > H - 1)
		{
			CUR_COL++;
			POS_H = 0;
		}
		tmp = tmp->next;
	}
}
/*
** Renvoie un pointeur sur un élément de la liste en fonction de POS_H, CUR_COL
** mode 1 = renvoie un pointeur sur le premier élément de la col courante.
*/
t_list	*get_elem(t_meta *meta, char mode)
{
	t_list		*tmp;
	t_ushort	i;

	save_pos(meta, 0);
	i = -1;
	tmp = meta->begin;
	if (mode == 1)
		POS_H = 0;
	while (++i < (CUR_COL * H + POS_H) && tmp->next)
		tmp = tmp->next;
	save_pos(meta, 1);
	return (tmp);
}
/*
 ** Supprime de la liste BEGIN, l'élement passé en paramètre. Décrémente la
 ** taille de la liste et re-initialise le padding en conséquence.
 ** Imprime à nouveau à partir du premier élément de la col courante.
 ** La dernière condition gère l'effacement de la première ligne de la col.
 */
t_list	*delete_elem(t_meta *meta, t_list *elem)
{
	t_list		*tmp;

	tmp = BEGIN;
	if (tmp == elem)
	{
		tmp = tmp->next;
		BEGIN = elem->next;
	}
	else
	{
		while (tmp->next != elem && tmp->next)
			tmp = tmp->next;
		tmp->next = elem->next;
		tmp = tmp->next;
	}
	free(elem);
	elem = tmp;
	if (!--LST_SIZE)
		ft_errors();
	init_pad(meta);
	print(meta, get_elem(meta, 1), 1);
	if (!POS_H && !elem)
		clear_line(meta, 1);
	return (elem);
}
/*
** Gère les opérations sur l'élément courant enregistré en statique.
** mode 0 = Trouve et mémorise l'élément courant en fonction de POS_H et CUR_COL
** et l'imprime souligné ;
** mode 1 = Annule le soulignement de l'élément mémorisé ;
** mode 2 = Sélectionne/désélectionne l'élément mémorisé. Ré-actualise
** l'impression en conséquence. Descend d'une case.
** mode 3 == Supprime l'élément mémorisé. Le remplace par l'élément qui suit
** dans la liste ou NULL. Si NULL, remonte d'une case. Ré-actualise l'impression
** de l'élément courant.
** mode 4 == Définie le nouveau CUR_COL et POS_H pour l'élément courant. Imprime
** en respectant l'ordonnancement des colonnes.
*/
void	ft_current(t_meta *meta, char mode)
{
	static t_list	*elem;
	t_ushort		pos_h;
	t_ushort		col;

	if (mode == 0)
		print_elem(meta, (elem = get_elem(meta, 0)),  mode);
	if (mode == 1)
		print_elem(meta, elem, mode);
	if (mode == 2)
	{
		elem->content_size ^= 1;
		ft_current(meta, 0);
		ft_move(meta, "BBB");
	}
	if (mode == 3)
	{
		if (!(elem = delete_elem(meta, elem)))
			move_up(meta);
		ft_current(meta, 0);
	}
	if (mode == 4)
	{
		set_pos(meta, elem);
		col = CUR_COL;
		CUR_COL = getstart(meta, CUR_COL);
		if (select_is_printable(meta))
			print(meta, get_elem(meta, 1), 0);
		else
		{
			init_screen(meta);
			dprintf(1, "PLEASE RESIZE\n");
		}
		POS_L = get_pos_l(meta, col, CUR_COL);
		CUR_COL = col;
		if (select_is_printable(meta))
			ft_current(meta, 0);
	}
}
