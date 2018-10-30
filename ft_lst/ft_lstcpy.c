#include "../includes/libft.h"

t_list			*ft_lstcpy(t_list **alst)
{
	t_list		*ret;
	t_list		*head;

	ret = NULL;
	if (!alst || !(head = *alst))
		return (NULL);
	while (head)
	{
		ft_lstappend(&ret, ft_lstnew(head->content, head->content_size));
		head = head->next;
	}
	return (ret);
}
