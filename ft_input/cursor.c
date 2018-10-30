#include "../includes/ft_input.h"
# include <termios.h>
# include <term.h>
# include <sys/ioctl.h>
# include <signal.h>

void			ft_cursor_term(int len, t_curs *cursor)
{
	len += ABS(cursor->back);
	if (len > (cursor->ws_col - cursor->prompt))
	{
		cursor->term++;
		len -= (cursor->ws_col - cursor->prompt);
		while (len > cursor->ws_col)
		{
			cursor->term++;
			len -= cursor->ws_col;
		}
	}
	else
		cursor->term++;
}

t_curs			*ft_init_cursor(char *prompt)
{
	t_curs		*ret;
	t_win		win;

	if (!(ret = (t_curs *)ft_memalloc(sizeof(t_curs))))
		return (NULL);
	ioctl(0, TIOCGWINSZ, &win);
	ret->prompt = (int)(ft_strlen(prompt));
	ret->col = 0;
	ret->row = 0;
	ret->ws_col = win.ws_col;
	ret->ws_row = win.ws_row;
	ret->back = 0;
	ret->term = 1;
	return (ret);
}

int				ft_curs_pos(t_curs *cursor)
{
	int			ret;

	ret = 0;
	if (!cursor)
		return (-1);
	ret = (cursor->ws_col * cursor->row) + cursor->col;
	return (ret);
}

void			ft_arrow_exec(int arrow, t_curs *cursor)
{
	if (arrow == 65)			/*haut (not used)*/
		return ;
	else if (arrow == 66)	/*bas (not used)*/
		return ;
	else if (arrow == 67 && cursor->back < 0)	/*droite	*/
	{
		if (cursor->col < cursor->ws_col - (!cursor->row ? cursor->prompt + 1 : 0))
		{
			ft_putstr(tgoto(tgetstr("nd", NULL), 0, 0));
			cursor->col++;
		}
		else
		{
			ft_putstr(tgoto(tgetstr("do", NULL), 0, 0));
			ft_putstr(tgoto(tgetstr("ch", NULL), 0, 0));
			cursor->col = 0;
			cursor->row++;
		}
		cursor->back++;
	}
	else if (arrow == 68)						/*gauche	*/
	{
		if (cursor->col > 0)
		{
			ft_putstr(tgoto(tgetstr("le", NULL), 0, 0));
			cursor->col--;
			cursor->back--;
		}
		else
		{
			if (cursor->row > 0)
			{
				ft_putstr(tgoto(tgetstr("up", NULL), 0, 0));
				ft_putstr(tgoto(tgetstr("ch", NULL), 0, cursor->ws_col - 1));
				cursor->row--;
				cursor->col = cursor->ws_col - (!cursor->row ? cursor->prompt + 1 : 0);
				cursor->back--;
			}
		}
	}
}
