#include "../includes/libft.h"

unsigned int		ft_bin_intoct(unsigned int nbr, unsigned short oct)
{
	unsigned int	flag;

	flag = 0;
	if (oct > 3)
		exit(1);
	flag = OCT(oct);
	return ((nbr & flag) >> (oct * 8));
}
