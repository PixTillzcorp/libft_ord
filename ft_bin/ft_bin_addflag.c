#include "../includes/libft.h"

unsigned int	ft_bin_addflag(unsigned int nbr, unsigned short oct, unsigned short pos)
{
	unsigned int	move;
	unsigned int	tmp;
	int				i;

	i = 0;
	if (oct > 3 || pos > 7)
		exit(1);
	tmp = ft_bin_intoct(nbr, oct);
	move = tmp << ((((sizeof(int) - 1) * 8)) + (8 - pos));
	move = move >> ((sizeof(int) * 8) - 1);
	if (!move)
		move++;
	else
		return (0);
	tmp = tmp | (move << pos);
	return (ft_bin_rplcoct(nbr, tmp, oct));
}
