#include "../includes/ft_input.h"
# include <termios.h>
# include <term.h>
# include <sys/ioctl.h>
# include <signal.h>

int				ft_putchar_stdin(int c)
{
	write(0, &c, 1);
	return (1);
}

void			ft_reset_term(t_term *save)
{
	if (tcsetattr(0, 0, save) == -1)
		return ;
	free(save);
}

t_term			*ft_init_term(void)
{
	t_term		term_stat;
	t_term		*save;
	char		*termname;

	if (!(save = (t_term *)ft_memalloc(sizeof(t_term))))
		return (NULL);
	if (!(termname = getenv("TERM")))
	{
		ft_putendl_fd("getenv error", 2);
		return (NULL);
	}
	if ((tgetent(NULL, termname)) == -1)
	{
		ft_putendl_fd("tgetent error", 2);
		return (NULL);
	}
	if (tcgetattr(0, save) == -1)
	{
		perror("tcgetattr: ");
		return (NULL);
	}
	if (tcgetattr(0, &term_stat) == -1)
		return (NULL);
	term_stat.c_lflag &= ~(ICANON);
	term_stat.c_lflag &= ~(ECHO);
	term_stat.c_cc[VMIN] = 1;
	term_stat.c_cc[VTIME] = 0;
	if (tcsetattr(0, TCSADRAIN, &term_stat) == -1)
		return (NULL);
	return (save);
}

void			ft_clear_screen(void)
{
	char		*ret;

	if (!(ret = tgetstr("cl", NULL)))
		return ;
	tputs(ret, 0, ft_putchar_stdin);
}
