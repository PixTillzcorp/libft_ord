#include "../includes/libft.h"

void		ft_putstr_free(char *str, int f)
{
	if (str)
	{
		write(1, str, ft_strlen(str));
		if (f)
			free(str);
	}
}
