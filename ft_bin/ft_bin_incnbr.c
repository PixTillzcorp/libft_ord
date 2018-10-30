#include "../includes/libft.h"

unsigned int		ft_bin_incnbr(unsigned int nbr)
{
	unsigned int	tmp;
	unsigned short	i;

	tmp = 0;
	i = 0;
	while (i < 4 && ft_bin_intoct(nbr, i) == 255)
	{
		nbr = ft_bin_rplcoct(nbr, (OCT(i) ^ OCT(i)), i);
		i++;
	}
	if (i >= 4)
		return (0);
	return (ft_bin_incoct(nbr, i));
}