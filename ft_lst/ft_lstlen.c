/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heinfalt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/27 16:00:29 by heinfalt          #+#    #+#             */
/*   Updated: 2017/09/29 10:00:41 by heinfalt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

int		ft_lstlen(t_list **alst)
{
	t_list		*head;
	int x;

	x = 0;
	if (!alst || !(head = *alst))
		return (0);
	while (head)
	{
		x++;
		head = head->next;
	}
	return (x);
}
