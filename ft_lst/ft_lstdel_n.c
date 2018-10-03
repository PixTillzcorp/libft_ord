#include "../includes/libft.h"

void			ft_lstdel_n(t_list **alst, int n)
{
	t_list		*head;
	t_list		*prev;

	if (!alst || !(head = *alst))
		return ;
	while (head->next && n - 1)
	{
		prev = head;
		head = head->next;
		n--;
	}
	prev->next = head->next;
	if (head->content)
		ft_memdel((void **)&head->content);
	free(head);
}
