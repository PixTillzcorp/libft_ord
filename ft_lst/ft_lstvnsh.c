#include "../includes/libft.h"

void ft_lstvnsh(t_list *elem)
{
	if (elem)
	{
		if (elem->content)
			ft_memdel((void **)&(elem->content));
		ft_memdel((void **)&(elem));
	}
}
