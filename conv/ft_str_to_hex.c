#include "../includes/libft.h"

char			*ft_str_to_hex(char *str)
{
	t_list		*lst;
	char		*tmp;
	int			i;

	i = 0;
	lst = NULL;
	while (str[i])
	{
		tmp = ft_dec_to_hex((unsigned int)str[i], 'x', 2);
		ft_lstappend(&lst, ft_lstnew(tmp, ft_strlen(tmp)));
		free(tmp);
		i++;
	}
	return (ft_lst_to_strcat(&lst));
}
