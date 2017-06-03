/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dec_to_sci.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heinfalt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/06 19:49:01 by heinfalt          #+#    #+#             */
/*   Updated: 2017/03/06 19:49:02 by heinfalt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

char		*ft_dec_to_sci(double nbr, char type, char *pre)
{
	char	*ret;
	int		exp;
	int		prec;

	exp = 0;
	ret = ft_strdup("");
	prec = (!ft_strcmp(pre, "0") ? 6 : ft_atoi(pre));
	if (nbr * -1 > 0)
	{
		nbr *= -1;
		ret = ft_chrjoin_free(ret, '-', 1);
	}
	while (nbr > 10 || nbr < 1)
	{
		exp = (nbr < 1 ? exp - 1 : exp + 1);
		nbr = (nbr < 1 ? nbr * 10 : nbr / 10);
	}
	ret = ft_strjoin_free(ret, ft_dbltoa(nbr, prec), 'l');
	ret = ft_chrjoin_free(ret, type, 1);
	ret = ft_chrjoin_free(ret, (exp < 0 ? '-' : '+'), 1);
	if (exp < 10)
		ret = ft_chrjoin_free(ret, '0', 1);
	return (ret = ft_strjoin_free(ret, ft_itoa(ABS(exp)), 'l'));
}
