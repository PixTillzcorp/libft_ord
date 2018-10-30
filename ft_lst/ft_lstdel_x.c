#include "../includes/libft.h"

void		ft_lstdel_x(t_list **alst, t_list *x)
{
	t_list	*head;
	t_list	*tmp;

	if (!alst || !(head = *alst))
		return ;
	if (head == x)
	{
		ft_lstdel_f(alst);
		return ;
	}
	tmp = NULL;
	while (head->next)
	{
		if (head->next == x)
		{
			tmp = head->next->next;
			ft_lstvnsh(head->next);
			head->next = tmp;
			return ;
		}
		head = head->next;
	}
}
