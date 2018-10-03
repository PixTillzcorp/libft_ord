#include "../includes/libft.h"

unsigned int	ft_bin_decoct(unsigned int nbr, unsigned short oct)
{
	unsigned int	tmp;

	if (oct > 3 || (tmp = ft_bin_intoct(nbr, oct)) > 255)
		exit(1);
	if (tmp > 0)
		tmp--;
	return (ft_bin_rplcoct(nbr, tmp, oct));
}
