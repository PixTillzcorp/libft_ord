#include "../includes/libft.h"

int				ft_strstart(const char *str, const char *start)
{
	int			i;

	i = 0;
	if (!str || !start)
		return (0);
	if (ft_strlen(str) < ft_strlen(start))
		return (0);
	while (start[i] && !(str[i] - start[i]))
		i++;
	if (i == (int)ft_strlen(start))
		return (1);
	else
		return (0);
}