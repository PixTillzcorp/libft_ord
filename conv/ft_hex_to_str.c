#include "../includes/libft.h"

char			*ft_hex_to_str(char *str)
{
	t_list		*lst;
	char		*tmp;
	int			dec;
	int			i;

	i = 0;
	lst = NULL;
	while (str[i])
	{
		tmp = ft_strjoin(ft_char_to_str(str[i]), ft_char_to_str(str[i + 1]));
		dec = ft_hex_to_dec(tmp, 'x');
		free(tmp);
		tmp = ft_char_to_str(dec);
		ft_lstappend(&lst, ft_lstnew(tmp, ft_strlen(tmp)));
		free(tmp);
		i += 2;
	}
	return (ft_lst_to_strcat(&lst));
}
