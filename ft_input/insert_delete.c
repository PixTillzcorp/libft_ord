#include "../includes/ft_input.h"
# include <termios.h>
# include <term.h>
# include <sys/ioctl.h>
# include <signal.h>

// void			ft_delscreen(t_list **alst, t_curs *cursor)
// {
// 	int			colmn;
// 	int			row;

// 	row = cursor->row + cursor->term;
// 	colmn = cursor->col + (cursor->row ? 0 : cursor->prompt);
// 	tputs(tgetstr("ce", NULL), 0, ft_putchar_stdin);
// 	while ((cursor->col + (ABS(cursor->back))) > cursor->ws_col)
// 	{
// 		ft_putstr(tgoto(tgetstr("ch", NULL), 0, 0));
// 		ft_putstr(tgoto(tgetstr("do", NULL), 0, 0));
// 		tputs(tgetstr("cd", NULL), 0, ft_putchar_stdin);
// 		ft_putstr(tgoto(tgetstr("cm", NULL), colmn, row));
// 	}
// 	ft_putnlst(alst, ft_curs_pos(cursor));
// 	ft_putstr(tgoto(tgetstr("cm", NULL), colmn, row));
// }

void			ft_putnlst(t_list **alst, int n)
{
	t_list		*head;

	if (!alst || !(head = *alst))
		return ;
	while (head)
	{
		if (n > 0)
			n--;
		else
			ft_putstr(head->content);
		head = head->next;
	}
}

void			ft_lstdel_n(t_list **alst, int n)
{
	t_list		*head;
	t_list		*prev;

	if (!alst || !(head = *alst))
		return ;
	while (head->next && n - 1)
	{
		prev = head;
		head = head->next;
		n--;
	}
	prev->next = head->next;
	if (head->content)
		ft_memdel((void **)&head->content);
	free(head);
}

void			ft_lstinsert(t_list **alst, t_list *new, int n)
{
	t_list		*head;
	t_list		*prev;

	if  (!alst || !(head = *alst) || !new)
		return ;
	if (n == 0)
	{
		new->next = *alst;
		*alst = new;
	}
	else
	{
		while (head->next && n)
		{
			prev = head;
			head = head->next;
			n--;
		}
		prev->next = new;
		new->next = head;
	}
}

void			ft_del_key(t_list **alst, t_curs *cursor)
{
	t_list		*head;

	if (!alst || !(head = *alst))
		return ;
	// ft_printf("col = {%d} | row = {%d} | back = {%d}\n", cursor->col, cursor->row, cursor->back);
	if (cursor->col > 0)
	{
		if (ft_curs_pos(cursor) == 1)
			ft_lstdel_f(alst);
		else
			ft_lstdel_n(alst, ft_curs_pos(cursor));
		ft_putstr(tgoto(tgetstr("le", NULL), 0, 0));
		tputs(tgetstr("dc", NULL), 0, ft_putchar_stdin);
		cursor->col--;
	}
	// else if (cursor->row > 0)
	// {
		
	// }
}
