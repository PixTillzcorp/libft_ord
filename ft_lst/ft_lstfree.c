#include "../includes/libft.h"

void				ft_lstfree(t_list **alst)
{
	t_list			*head;
	t_list			*tmp;

	if (!alst || !(head = *alst))
		return ;
	while (head)
	{
		tmp = head->next;
		if (head->content)
			ft_memdel((void **)&head->content);
		free(head);
		head = tmp;
	}
	alst = NULL;
}