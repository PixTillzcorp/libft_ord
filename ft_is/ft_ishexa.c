#include "../includes/libft.h"

int		ft_ishexa(int c, int digit, char type)
{
	if (((c >= 97 && c <= 102) && type == 'x') || ((c >= 65 && c <= 70) && type == 'X'))
		return (1);
	else if (digit && ft_isdigit(c))
		return (1);
	return (0);
}
