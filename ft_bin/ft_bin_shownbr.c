#include "../includes/libft.h"

void			ft_bin_shownbr(unsigned int nbr)
{
	int				i;

	i = 3;
	while (i >= 0)
	{
		ft_bin_showoct(nbr, i--);
		if (i != -1)
			ft_putchar('|');
	}
	ft_putchar('\n');
}
