#include "../includes/libft.h"

char		*ft_strchain(int c, int len)
{
	char	*ret;
	int	i;

	i = 0;
	ret = (char *)ft_memalloc(sizeof(char) * len + 1);
	while (i < len)
		ret[i++] = c;
	ret[i] = '\0';
	return (ret);
}

