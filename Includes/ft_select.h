
#ifndef FT_SELECT_H
# define FT_SELECT_H
# include <term.h>
# undef tab
# include <curses.h>
# include <stdio.h>
# include <sys/ioctl.h>
# include <sys/stat.h>
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
# define BEGIN (meta->begin)
# define COL_PR meta->col_pr
# define ELEM meta->elem

#define ANSI_COLOR_RED     "\x1b[31m"
#define ANSI_COLOR_GREEN   "\x1b[32m"
#define ANSI_COLOR_YELLOW  "\x1b[33m"
#define ANSI_COLOR_BLUE    "\x1b[34m"
#define ANSI_COLOR_MAGENTA "\x1b[35m"
#define ANSI_COLOR_CYAN    "\x1b[36m"
#define ANSI_COLOR_RESET   "\x1b[0m"

typedef	unsigned short t_ushort;
typedef struct termios t_termios;
typedef struct winsize t_winsize;
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
		t_ushort	lst_size;
		t_list		*begin;
		t_list		*elem;
		char		*path;
}					t_meta;

int					fputchar(int c);
/*
**move.c
*/
void				ft_move(t_meta *meta, char *buf);
void				move_left(t_meta *meta);
void				move_right(t_meta *meta);
void				move_up(t_meta *meta);
void				move_down(t_meta *meta);
t_ushort			getstart(t_meta *meta, t_ushort cur_col);
t_ushort			get_pos_l(t_meta *meta, t_ushort cur_col, t_ushort col_start);
/*
**main.c
*/
int					get_fd(int fd);
void				debug(t_meta *meta);
void				exit_select(t_meta *meta, int i);
int					read_keys(t_meta *meta);
t_meta				*get_meta(t_meta *meta);
t_termios			*handle_term(char c);
/*
**print.c
*/
void				clear_line(t_meta *meta, char mode);
void				init_screen(t_meta *meta);
void				save_pos(t_meta *meta, char mode);
void				print_elem(t_meta *meta, t_list *elem, char mode);
void				print(t_meta *meta, t_list *begin, char mode);
/*
** signal.c
*/
void				set_signals(void);
void				handle_sig(int sig);
/*
** errors.c
*/
void				ft_errors(void);
/*
** init.c
*/
void				init_list(t_meta *meta, char **av);
void				init_pos(t_meta *meta, char *str);
void				init_curseur(t_meta *meta, char mode);
int					init_pad(t_meta *meta);
int					init_term(t_meta *meta);
/*
** elems.c
*/
void				ft_current(t_meta *meta, char mode);
t_list				*get_elem(t_meta *meta, char mode);
t_list				*delete_elem(t_meta *meta, t_list *elem);
/*
** support.c
*/
int					open_fd(void);
void				ft_set_color(size_t content_size);
#endif
