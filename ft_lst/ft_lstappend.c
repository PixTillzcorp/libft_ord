/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstappend.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heinfalt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/26 16:30:16 by heinfalt          #+#    #+#             */
/*   Updated: 2016/11/26 16:30:17 by heinfalt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

void	ft_lstappend(t_list **alst, t_list *new)
{
	t_list		*head;

	if (!alst)
		return ;
	if (!(head = *alst))
		*alst = new;
	else
	{
		while (head->next)
			head = head->next;
		head->next = new;
	}
}
