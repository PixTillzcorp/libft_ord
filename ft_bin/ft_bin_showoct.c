#include "../includes/libft.h"

void				ft_bin_showoct(unsigned int nbr, unsigned short oct)
{
	unsigned char	tmp;
	unsigned char	print;
	int				i;

	i = 0;
	if (oct > 3)
		exit(1);
	tmp = (unsigned char)ft_bin_intoct(nbr, oct);
	while (i < 8)
	{
		print = tmp << i++;
		ft_putchar((print >> 7) + 48);
	}
}
