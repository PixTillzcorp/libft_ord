#include "../includes/ft_input.h"
# include <termios.h>
# include <term.h>
# include <sys/ioctl.h>
# include <signal.h>

static int		char_on_line(size_t len, size_t col)
{
	if (col)
		return ((len % col));
	return (0);
}

static int		nb_line(size_t len, size_t col)
{
	if (len <= col)
		return (1);
	else if (col)
		return (len / col + ((len % col) ? 1 : 0));
	return (0);
}

static void		ft_putlst_chr(t_list **alst)
{
	t_list		*head;

	if (!alst || !(head = *alst))
		return ;
	else
	{
		while (head)
		{
			ft_putstr(((char *)head->content));
			head = head->next;
		}
	}
}

static void		ft_print_line(t_list **alst, t_curs *cursor, char *prompt, size_t length)
{
	t_win		win;
	int			y;

	if (!alst)
		return ;
	ioctl(0, TIOCGWINSZ, &win);
	if (cursor->ws_col != win.ws_col)
		y = nb_line(length + cursor->prompt, win.ws_col);
	else
		y = cursor->row;
	ft_putstr(tgoto(tgetstr("ch", NULL), 0, 0));
	while (--y > 0)
	{
		ft_putstr(tgoto(tgetstr("ce", NULL), 0, 0));
		ft_putstr(tgoto(tgetstr("up", NULL), 0, 0));
	}
	ft_putstr(tgoto(tgetstr("ce", NULL), 0, 0));
	ft_putstr(prompt);
	ft_putchar(' ');
	ft_putlst_chr(alst);
	ft_putchar(' ');
	ft_putstr(tgoto(tgetstr("cd", NULL), 0, 0));
}

static void		ft_cursor_check(t_curs *cursor)
{
	t_win		win;

	ioctl(0, TIOCGWINSZ, &win);
	cursor->ws_col = win.ws_col;
	cursor->ws_row = win.ws_row;
}

static void		ft_update_cursor(t_curs *cursor, size_t length)
{
	int	roll;

	roll = cursor->back - 1;
	if (roll < 0)
	{
		while (roll < 0)
		{
			// ft_printf("char_on_line = %d for length = %d and col = %d\n", char_on_line(length + cursor->prompt, cursor->ws_col), length + cursor->prompt, cursor->ws_col);
			if ((roll * -1) > cursor->ws_col)
			{
				ft_putstr(tgoto(tgetstr("up", NULL), 0, 0));
				roll += cursor->ws_col;
			}
			else if ((roll * -1) > char_on_line(length + cursor->prompt, cursor->ws_col))
			{
				ft_putstr(tgoto(tgetstr("up", NULL), 0, 0));
				ft_putstr(tgoto(tgetstr("ch", NULL), 0, cursor->ws_col));
				roll += char_on_line(length + cursor->prompt, cursor->ws_col);
			}
			else
			{
				ft_putstr(tgoto(tgetstr("le", NULL), 0, 0));
				roll++;
			}
		}
	}
}

void		ft_update(t_list **alst, t_curs *cursor, char *prompt, size_t length)
{
	if (!alst)
		return ;
	if (length != (size_t)ft_lstlen(alst))
	{
		ft_print_line(alst, cursor, prompt, length);
		ft_update_cursor(cursor, length);
	}
	ft_cursor_check(cursor);
}
