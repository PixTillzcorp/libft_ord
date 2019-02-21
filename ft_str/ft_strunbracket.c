#include "../includes/libft.h"

static int		ft_isbracket(int c)
{
	if (c == '(')
		return (1);
	if (c == '{')
		return (3);
	if (c == '[')
		return (5);
	if (c == ')')
		return (2);
	if (c == '}')
		return (4);
	if (c == ']')
		return (6);
	return (0);
}

char		*ft_strunbracket(const char *str)
{
	char	*ret;
	int		f_bracket;
	int		l_bracket;
	int		len;
	int		i;

	i = 0;
	if (!str || !(f_bracket = ft_isbracket(str[i++])))
		return (NULL);
	if ((len = ft_strlen(str) - 1) <= 1)
		return (ft_strdup(""));
	if (!(l_bracket = ft_isbracket(str[len])) || f_bracket != l_bracket - 1)
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
