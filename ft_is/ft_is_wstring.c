#include "../libft.h"

int	ft_is_wstring(wint_t *str)
{
	int i;

	i = 0;
	while (str[i])
	{
		if (str[i++] - 127 > 0)
			return (1);
	}
	return (0);
}

