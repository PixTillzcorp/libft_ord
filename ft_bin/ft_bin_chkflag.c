#include "../includes/libft.h"

int			ft_bin_chkflag(unsigned int nbr, unsigned short oct, unsigned int skull)
{
	if (oct > 3)
		return (0);
	if (!((nbr >> (oct * 8)) ^ skull)) //only works for the last octet
		return (1);
	return (0);
}
