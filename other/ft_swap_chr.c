#include "../includes/libft.h"

void		ft_swap_chr(char **a, char **b)
{
	char	*swap;

	swap = *a;
	*a = *b;
	*b = swap;
}
