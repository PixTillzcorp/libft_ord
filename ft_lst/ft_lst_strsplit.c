#include "../includes/libft.h"

t_list			*ft_lst_strsplit(char *str, char split)
{
	t_list		*ret;
	char		*tmp;
	size_t		len;
	int			i;

	if (!str || !split)
		return (NULL);
	len = ft_strlen(str);
	tmp = str;
	ret = NULL;
	i = 0;
	while (tmp[i])
	{
		if (tmp[i] == split)
		{
			tmp[i] = '\0';
			ft_lstappend(&ret, ft_lstnew(ft_strdup(tmp), ft_strlen(tmp)));
			if ((size_t)(i + 1) < len)
				tmp += i + 1;
			else
				break ;
			len -= (size_t)(i + 1);
			i = 0;
		}
		else if ((size_t)(i + 1) == len)
		{
			ft_lstappend(&ret, ft_lstnew(ft_strdup(tmp), ft_strlen(tmp)));
			i++;
		}
		else
			i++;
	}
	if (str)
		ft_memdel((void **)&str);
	return (ret);
}
