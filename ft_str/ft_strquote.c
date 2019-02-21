#include "../includes/libft.h"

char		*ft_strquote(const char *str, char type)
{
	char	*ret;
	int		i;

	i = 0;
	if (!str || !ft_isquote(type))
		return (NULL);
	if (!(ret = (char *)ft_memalloc(sizeof(char) * (ft_strlen(str) + 3))))
		return (NULL);
	ret[i] = type;
	while (str[i])
	{
		ret[i + 1] = str[i];
		i++;
	}
	ret[i + 1] = type;
	return (ret);
}
