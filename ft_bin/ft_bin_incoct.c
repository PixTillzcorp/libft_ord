#include "../includes/libft.h"

unsigned int		ft_bin_incoct(unsigned int nbr, unsigned short oct)
{
	unsigned int	tmp;

	if (oct > 3)
	{
		ft_printf("oct = {%d}\n", oct);
		exit(1);
	}
	if ((tmp = ft_bin_intoct(nbr, oct)) < 255)
		tmp++;
	return (ft_bin_rplcoct(nbr, tmp, oct));
}
