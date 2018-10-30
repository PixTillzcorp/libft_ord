#include "../includes/libft.h"

void		ft_lstdel_str(t_list **alst, char *str, char *(*f)(char *))
{
	t_list	*head;
	t_list	*tmp;
	char	*key;

	key = NULL;
	if (!alst || !(head = *alst) || !str)
		return ;
	while (head)
	{
		if (!(key = f(head->content)))
			return ;
		if (!ft_strcmp(key, str))
		{
			tmp = head->next;
			ft_lstdel_x(alst, head);
			head = tmp;
			return ;
		}
		else
			head = head->next;
		if (key)
			ft_memdel((void **)&key);
	}
}
