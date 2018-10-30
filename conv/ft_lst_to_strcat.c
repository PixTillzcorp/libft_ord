#include "../includes/libft.h"

char		*ft_lst_to_strcat(t_list **alst)
{
	t_list		*head;
	char		*ret;
	int			len;
	int			i;

	if (!alst || !(head = *alst) || !head->content)
		return (NULL);
	len = 0;
	i = 0;
	while (head)
	{
		len += (int)ft_strlen((char *)head->content);
		head = head->next;
	}
	head = *alst;
	if (!(ret = (char *)ft_memalloc(sizeof(char) * (len + 1))))
		return (NULL);
	while (head)
	{
		ret = ft_strcat(ret, (char *)(head->content));
		head = head->next;
	}
	ft_lstfree(alst);
	return (ret);
}
