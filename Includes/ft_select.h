
#ifndef FT_SELECT_H
# define FT_SELECT_H
# include <term.h>
# undef tab
# include <curses.h>
# include <stdio.h>
# include "../Libs/libft/Includes/libft.h"

# define SPACING 5
# define RIGHT 0
# define LEFT 1
# define UP 2
# define DOWN 3
# define POS_L meta->pos_l
# define POS_H meta->pos_h
# define CUR_COL meta->cur_col
# define COL_PAD meta->col_pad
# define COL_NB meta->col_nb
# define H meta->h
# define L meta->l
# define LST_SIZE meta->lst_size
# define BEGIN meta->begin
# define COL_PR meta->col_pr
# define LAST meta->last

typedef	unsigned short t_ushort;
typedef struct termios t_termios;
typedef	struct	s_meta
{
		t_ushort	pos_l;
		t_ushort	pos_h;
		t_ushort	cur_col;
		t_ushort	*col_pad;
		t_ushort	col_nb;
		t_ushort	col_pr;
		t_ushort	h;
		t_ushort	l;
		t_ushort	last;
		t_ushort	lst_size;
		t_list		*begin;
		char		*path;
}					t_meta;

int					fputchar(int c);

void				ft_current(t_meta *meta, char mode);
void				ft_move(t_meta *meta, char key);

void				handle_term(char c);
void				init_list(t_meta *meta, char **av);
void				init_pos(t_meta *meta, char *str);
/*
**print.c
*/
void				save_pos(t_meta *meta, char mode);
void				print_elem(t_meta *meta, t_list *elem, char mode);
void				print(t_meta *meta, t_list *begin);
/*
** signal.c
*/
void				set_signals(void);
void				handle_sig(int sig);
/*
** errors.c
*/
void				ft_errors(void);

#endif
