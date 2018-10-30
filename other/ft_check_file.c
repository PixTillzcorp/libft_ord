#include "../includes/libft.h"

int			ft_check_file(const char *path)
{
	struct stat		s;

	if (lstat(path, &s) == 0 && ft_data_type(s.st_mode & S_IFMT) == '-')
		return (1);
	return (0);
}
