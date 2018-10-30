#include "../includes/libft.h"

char		*ft_char_to_str(int chr)
{
	char		*ret;

	if (!(ret = (char *)ft_memalloc(sizeof(char) * 2)))
		return (NULL);
	ret[0] = chr;
	return (ret);
}
