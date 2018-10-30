#include "../includes/libft.h"

void		ft_lstjoin(t_list **alst, t_list *next)
{
	t_list	*head;

	if (!alst || !(head = *alst) || !next)
		return ;
	while (head->next)
		head = head->next;
	head->next = next;
}
