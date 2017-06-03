#include "../libft.h"

void	ft_putxchar(char c, int x)
{
	if (x > 0)
	{
		while (x != 0)
		{
			write(1, &c, 1);
			x--;
		}
	}
}
