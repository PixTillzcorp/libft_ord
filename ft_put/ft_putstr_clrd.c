#include "../includes/libft.h"

void		ft_putstr_clrd(char *str, char *color)
{
	if (str && color)
	{
		ft_putstr(color);
		ft_putstr(str);
		ft_putstr("\033[0m");
	}
}
