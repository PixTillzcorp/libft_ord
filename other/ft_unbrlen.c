#include "../includes/libft.h"

int		ft_unbrlen(unsigned int nbr)
{
	int count;

	count = 1;
	while (nbr != 0)
	{
		nbr /= 10;
		if (nbr != 0)
			count++;
		else
			break ;
	}
	return (count);
}
