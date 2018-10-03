#include "../includes/libft.h"

void			ft_lstdel_f(t_list **alst)
{
	t_list		*head;

	if (!alst || !(head = *alst))
		return ;
	if (head->next)
		*alst = (*alst)->next;
	else
		*alst = NULL;
	if (head->content)
		ft_memdel((void **)&head->content);
	free(head);
}
