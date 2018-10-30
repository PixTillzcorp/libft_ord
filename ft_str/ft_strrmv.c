#include "../includes/libft.h"

char		*ft_strrmv(char *str, int rm)
{
	char	*ret;
	int		len;
	int		i;

	i = 0;
	len = 0;
	while (str[i])
	{
		i++;
		if (str[i] != rm)
			len++;
	}
	if (!(ret = (char *)ft_memalloc(sizeof(char) * (len + 1))))
		return (NULL);
	i = 0;
	len = 0;
	while (str[i])
	{
		if (str[i] != rm)
			ret[len++] = str[i++];
		else
			i++;
	}
	if (str)
		ft_memdel((void **)&str);
	return (ret);
}
