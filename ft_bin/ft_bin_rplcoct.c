#include "../includes/libft.h"

unsigned int		ft_bin_rplcoct(unsigned int nbr, unsigned int newoct, unsigned short oct)
{
	unsigned int	flag;

	flag = 0;
	if (oct > 3 || newoct > 255)
	{
		ft_printf("oct = {%u} | new oct = {%u}\n", oct, newoct);
		ft_bin_shownbr(newoct);
		exit(1);
	}
	flag = ~(OCT(oct));
	return (((nbr & flag) ^ (newoct << (oct * 8))));
}
