#include "../includes/libft.h"

void	*ft_memrealloc(void *old, size_t oldsize, size_t newsize)
{
	void	*new;

	if ((new = ft_memalloc(newsize)))
		new = ft_memcpy(new, old, oldsize);
	ft_memdel(&old);
	return (new);
}
