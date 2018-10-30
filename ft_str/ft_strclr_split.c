#include "../includes/libft.h"

char		*ft_strclr_split(char *str, char split)
{
	t_list	*head;
	int		i;

	i = 0;
	head = NULL;
	while (str[i])
	{
		if (str[i] == split)
		{
			while (str[i] && str[i] == split)
				i++;
			if (str[i])
				ft_lstappend(&head, ft_lstnew(ft_char_to_str((int)split), 2));
		}
		else
			ft_lstappend(&head, ft_lstnew(ft_char_to_str((int)str[i++]), 2));
	}
	return (ft_lst_to_str(&head));
}
