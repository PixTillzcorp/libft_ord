#include "../includes/libft.h"

void			ft_lstinsert(t_list **alst, t_list *new, int n)
{
	t_list		*head;
	t_list		*prev;

	if  (!alst || !(head = *alst) || !new)
		return ;
	if (n == 0)
	{
		new->next = *alst;
		*alst = new;
	}
	else
	{
		while (head->next && n)
		{
			prev = head;
			head = head->next;
			n--;
		}
		prev->next = new;
		new->next = head;
	}
}
