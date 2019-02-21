#include "../includes/ft_input.h"
# include <termios.h>
# include <term.h>
# include <sys/ioctl.h>
# include <signal.h>

static int		ft_is_strprint(char *str)
{
	int			i;

	i = 0;
	if (!str)
		return (0);
	while (str[i])
	{
		if (!ft_isprint(str[i++]))
			return (0);
	}
	return (1);
}

static int		ft_pasteboard(t_list **alst, t_curs *cursor, char *str)
{
	int			i;

	i = 0;
	while (str[i])
	{
		if (!(cursor->back))
			ft_lstappend(alst, ft_lstnew((str + i), sizeof(char)));
		else
			ft_lstinsert(alst, ft_lstnew((str + i), sizeof(char)), ft_curs_pos(cursor));
		i++;
		if (cursor->col == cursor->ws_col - (!cursor->row ? cursor->prompt : 0))
		{
			cursor->col = 1;
			cursor->row++;
		}
		else
			cursor->col++;
	}
	return (i);
}

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
		if (cursor->col == cursor->ws_col - (!cursor->row ? cursor->prompt : 0))
		{
			cursor->col = 1;
			cursor->row++;
		}
		else
			cursor->col++;
	}
	else if (ft_strlen(keys) > 1 && ft_is_strprint(keys))
		ft_pasteboard(alst, cursor, keys);
	// if (cursor->back < 0)
	// 	ft_delscreen(alst, cursor);
	free(keys);
	return (0);
}

char			*ft_read_canon(char *prompt, t_curs *cursor, int secured)
{
	t_list		*line;
	size_t		length;
	char		*buff;
	char		*ret;

	line = NULL;
	length = 0;
	while (1)
	{
		if (line)
			length = ft_lstlen(&line);
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
			if (line && !secured)
				ft_update(&line, cursor, prompt, length);
			break;
		}
		if (!secured)
			ft_update(&line, cursor, prompt, length);
	}
	tputs(tgetstr("ei", NULL), 0, ft_putchar_stdin);				/*Exit insert (security)*/
	if ((ret = ft_lst_to_str(&line)))
		return (ret);
	return (NULL);
}

char		*ft_input(char *prompt, int secured)
{
	t_curs		*cursor;
	t_term		*save;
	char		*ret;

	if (!(save = ft_init_term()))
		return (NULL);
	if (!(cursor = ft_init_cursor(prompt)))
		return (NULL);
	if (secured)
	{
		ft_putstr("password ->");
		tputs(tgetstr("vi", NULL), 0, ft_putchar_stdin);
	}
	else
		ft_putstr(prompt);
	ft_putchar(' ');
	ret = ft_read_canon(prompt, cursor, secured);
	tputs(tgetstr("ve", NULL), 0, ft_putchar_stdin);
	ft_reset_term(save);
	return (ret);
}


// int			main(void)       NEW
// {
// 	char	*ret;

// 	ret = "";
// 	while (!ret || ft_strcmp(ret, "exit"))
// 		ret = ft_input("hippolyte->");
// 	return (0);
// }

/*int				main(...)    OLD			*/
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
