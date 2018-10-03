#include "../includes/commandline.h"
# include <termios.h>
# include <term.h>
# include <sys/ioctl.h>
# include <signal.h>

static int		ft_key(t_list **alst, t_curs *cursor, char *keys)
{
	if (keys[0] == 27 && keys[1] == 91)						/*Arrows*/
		ft_arrow_exec(keys[2], cursor);
	else if (keys[0] == 127 && !keys[1])					/*Delete*/
		ft_del_key(alst, cursor);
	else if (keys[0] == 10 && !keys[1])						/*Enter*/
		return (ft_putchar_stdin('\n'));					/*Return (1)*/
	else if ((keys[0] >= 32 && keys[0] <= 126) && !keys[1])	/*Normal keys*/
	{
		if (!(cursor->back))
			ft_lstappend(alst, ft_lstnew(keys, ft_strlen(keys)));
		else
			ft_lstinsert(alst, ft_lstnew(keys, ft_strlen(keys)), ft_curs_pos(cursor));
		ft_putchar(keys[0]);
		if (cursor->col == cursor->ws_col - (!cursor->row ? cursor->prompt : 0))
		{
			cursor->col = 1;
			cursor->row++;
		}
		else
			cursor->col++;
	}
	// if (cursor->back < 0)
	// 	ft_delscreen(alst, cursor);
	free(keys);
	return (0);
}

char			*ft_input(char *prompt, t_curs *cursor)
{
	t_list		*line;
	char		*buff;
	char		*ret;

	line = NULL;
	cursor->col = 0;
	cursor->row = 0;
	cursor->back = 0;
	ft_putstr(prompt);
	while (1)
	{
		if (cursor->back < 0)
			tputs(tgetstr("im", NULL), 0, ft_putchar_stdin);		/*Insert mode*/
		else
			tputs(tgetstr("ei", NULL), 0, ft_putchar_stdin);		/*Exit insert*/
		if (!(buff = (char *)ft_memalloc(sizeof(char) * (3 + 1))))
			return (NULL);
		if (read(0, buff, 3) == -1)
			return (NULL);
		if (ft_key(&line, cursor, buff))
		{
			ft_memdel((void **)&buff);
			break;
		}
	}
	tputs(tgetstr("ei", NULL), 0, ft_putchar_stdin);				/*Exit insert (security)*/
	if ((ret = ft_lst_to_str(&line)))
	{
		if (line)
			ft_cursor_term((int)ft_strlen(ret), cursor);
		return (ret);
	}
	else
		ft_cursor_term(0, cursor);
	ft_putstr(tgoto(tgetstr("cm", NULL), 0, cursor->term));
	return (NULL);
}

/*int				main(...)					*/
/*{												*/
/*	t_curs		*cursor;						*/
/*	t_term		*save;							*/
/*	char		*ret;							*/
/*												*/
/*	if (!(save = ft_init_term()))				*/
/*		return (1);								*/
/*	ft_clear_screen();							*/
/*	if (!(cursor = ft_init_cursor(argv[1])))	*/
/*		return (1);								*/
/*	while (1)									*/
/*	{											*/
/*		ret = ft_input(argv[1], cursor);		*/
/*		if (ret)								*/
/*			free(ret);							*/
/*	}											*/
/*	ft_reset_term(save);						*/
/*}												*/