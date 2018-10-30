#include "../includes/libft.h"

void			ft_lstsnipe(t_list **alst, t_list *target)
{
	t_list		*head;
	t_list		*tmp;

	if (!alst || !(head = *alst) || !target)
		return ;
	if (head == target)
	{
		*alst = (*alst)->next;
		free(head->content);
		free(head);
		return ;
	}
	while (head)
	{
		if (head->next == target)
		{
			tmp = head->next;
			head->next = tmp->next;
			free(tmp->content);
			free(tmp);
			return ;
		}
		head = head->next;
	}
}
