#include "../includes/libft.h"

int	ft_isquote(int c)
{
	if (c == '\"')
		return (1);
	if (c == '\'')
		return (2);
	return (0);
}
