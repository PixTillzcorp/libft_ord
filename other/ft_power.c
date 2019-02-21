#include "../includes/libft.h"

unsigned int	ft_power(unsigned int nbr, int pow)
{
	int			tmp;

	if (!nbr || pow < 0)
		return (0);
	if (!pow)
		return (1);
	if (pow == 1)
		return (nbr);
	tmp = nbr;
	while (pow != 1)
	{
		nbr *= tmp;
		pow--;
	}
	return (nbr);
}