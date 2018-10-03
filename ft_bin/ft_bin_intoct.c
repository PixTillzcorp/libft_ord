#include "../includes/libft.h"

unsigned int		ft_bin_intoct(unsigned int nbr, unsigned short oct)
{
	unsigned int	flag;

	flag = 0;
	if (oct > 3)
		exit(1);
	if (oct == 0)
		flag = OCT_1;
	else if (oct == 1)
		flag = OCT_2;
	else if (oct == 2)
		flag = OCT_3;
	else if (oct == 3)
		flag = OCT_4;
	return ((nbr & flag) >> (oct * 8));
}
