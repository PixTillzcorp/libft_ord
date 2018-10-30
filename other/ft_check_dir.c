#include "../includes/libft.h"

int			ft_check_dir(const char *path)
{
	struct stat		s;

	if (lstat(path, &s) == 0 && ft_data_type(s.st_mode & S_IFMT) == 'd')
		return (1);
	return (0);
}
