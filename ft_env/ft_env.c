/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_env.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heinfalt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/08 15:41:24 by heinfalt          #+#    #+#             */
/*   Updated: 2018/03/08 15:41:37 by heinfalt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

void			ft_env(t_list **adr_env)
{
	t_list		*cpy;

	if (adr_env)
	{
		cpy = (*adr_env);
		while (cpy)
		{
			ft_printf("{%s}\n", cpy->content);
			// ft_putendl(cpy->content);
			cpy = cpy->next;
		}
	}
}
