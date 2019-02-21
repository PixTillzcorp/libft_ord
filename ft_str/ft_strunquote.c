#include "../includes/libft.h"

char		*ft_strunquote(const char *str)
{
	char	*ret;
	char	f_quote;
	char	l_quote;
	int		len;
	int		i;

	i = 0;
	if (!str || !(f_quote = ft_isquote(str[i++])))
		return (NULL);
	if ((len = ft_strlen(str) - 1) <= 1)
		return (ft_strdup(""));
	if (!(l_quote = ft_isquote(str[len])) || f_quote != l_quote)
		return (NULL);
	if (!(ret = (char *)ft_memalloc(sizeof(char) * (len))))
		return (NULL);
	while (str[i] && i < len)
	{
		ret[i - 1] = str[i];
		i++;
	}
	return (ret);
}
