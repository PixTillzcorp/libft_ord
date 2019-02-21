#include "../includes/libft.h"

char			*ft_strrand(int type, size_t len)
{
	char		*ret;

	if (type != 'x' && type != 'X')
		return (NULL);
	type = (type == 'x' ? 97 : 65);
	ret = ft_strdup("");
	while (ft_strlen(ret) != len)
		ret = ft_strjoin_free(ret, ft_dec_to_hex((char)((arc4random() % 26) + type), 'x', 2), 'b');
	return (ret);
}
