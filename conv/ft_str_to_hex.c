#include "../includes/libft.h"

static int	ft_size_hex(int nbr)
{
	int		len;

	len = 0;
	while (nbr)
	{
		nbr = nbr / 16;
		len++;
	}
	return (len);
}

static char	*ft_dec_flush_hex(int nbr, char type, int pre)
{
	char	*ret;
	int		rest;
	int		min_maj;
	int		i;

	if (!nbr)
		return (ft_strdup("00"));
	i = ft_size_hex(nbr);
	ret = (char *)ft_memalloc(sizeof(char) * ((i < pre ? pre : i) + 1));
	i = 0;
	min_maj = (type == 'x' ? 97 : 65);
	while (nbr)
	{
		rest = nbr % 16;
		nbr = nbr / 16;
		if (rest >= 10)
			ret[i++] = (min_maj + (rest % 10));
		else
			ret[i++] = (rest + 48);
	}
	while (i < pre)
		ret[i++] = '0';
	return (ft_retstr_free(ret, ft_strrev(ret)));
}

char		*ft_str_to_hex(char	*str, char type)
{
	t_list	*ret;
	int		i;

	i = 0;
	ret = NULL;
	if (!str || (type != 'X' && type != 'x'))
		return (NULL);
	while (str[i])
		ft_lstappend(&ret, ft_lstnew(ft_dec_flush_hex(str[i++], type, 2), 2));
	return (ft_lst_to_strcat(&ret));
}
