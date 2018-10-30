#include "../includes/libft.h"

t_list		*ft_file_get(int fd)
{
	t_list	*list;
	char	*line;
	int		ret;

	list = NULL;
	line = NULL;
	while ((ret = get_next_line(fd, &line)))
	{
		ft_lstappend(&list, ft_lstnew(line, ft_strlen(line)));
		free(line);
	}
	if (ret < 0)
	{
		ft_putendl("get_next_line error.");
		return (NULL);
	}
	return (list);
}
