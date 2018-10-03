#include "../includes/libft.h"

unsigned int		ft_bin_valoct(unsigned int nbr, unsigned short oct, int value)
{
	unsigned int	tmp;

	if (oct > 3)
		exit(1);
	tmp = ft_bin_intoct(nbr, oct);
	while (value)
	{
		if (tmp == 0 || tmp == 255)
			break ;
		else
		{
			tmp += (value < 0 ? -1 : 1);
			value += (value < 0 ? 1 : -1);
		}
	}
	return (ft_bin_rplcoct(nbr, tmp, oct));
}
