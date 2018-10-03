#include "../includes/libft.h"

char			*ft_lst_to_str(t_list **alst)
{
	t_list		*head;
	char		*ret;
	int			i;

	if (!alst || !(head = *alst) || !head->content)
		return (NULL);
	if (!(ret = (char *)ft_memalloc(sizeof(char) * (ft_lstlen(alst) + 1))))
		return (NULL);
	i = 0;
	while (head)
	{
		ret[i++] = ((char *)(head->content))[0];
		head = head->next;
	}
	ft_lstfree(alst);
	return (ret);
}
