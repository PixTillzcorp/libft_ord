#include "../includes/libft.h"

int		ft_strnchr(const char *str, int flag)
{
	int	ret;
	int	i;

	i = 0;
	ret = 0;
	while (str[i])
	{
		if (str[i] == flag)
			ret++;
		i++;
	}
	return (ret);
}
