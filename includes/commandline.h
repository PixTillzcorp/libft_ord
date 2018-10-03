#ifndef COMMANDLINE_H
# define COMMANDLINE_H

# include "libft.h"

typedef struct	termios	t_term;
typedef struct	winsize t_win;

typedef struct			s_curs
{
	int					prompt;
	int					col;
	int					row;
	int					ws_col;
	int					ws_row;
	int					back;
	int					term;
}						t_curs;

char					*ft_input(char *prompt, t_curs *cursor);
void					ft_arrow_exec(int arrow, t_curs *cursor);
t_curs					*ft_init_cursor(char *prompt);
void					ft_del_key(t_list **alst, t_curs *cursor);
int						ft_curs_pos(t_curs *cursor);
int						ft_putchar_stdin(int c);
void					ft_reset_term(t_term *save);
t_term					*ft_init_term(void);
void					ft_clear_screen(void);
void					ft_putnlst(t_list **alst, int n);
void					ft_delscreen(t_list **alst, t_curs *cursor);
void					ft_cursor_term(int len, t_curs *cursor);

#endif