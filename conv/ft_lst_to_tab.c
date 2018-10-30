#include "../includes/libft.h"

char		**ft_lst_to_tab(t_list **alst)
{
	t_list	*head;
	char	**ret;
	int		i;

	if (!alst || !(head = *alst))
		return (NULL);
	if (!(ret = (char **)ft_memalloc(sizeof(char *) * (ft_lstlen(alst) + 1))))
		return (NULL);
	i = 0;
	while (head)
	{
		ret[i++] = ft_strdup((char *)(head->content));
		head = head->next;
	}
	ft_lstfree(alst);
	return (ret);
}
