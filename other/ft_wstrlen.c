#include "../libft.h"

size_t		ft_wstrlen(wint_t *str)
{
	size_t i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}
