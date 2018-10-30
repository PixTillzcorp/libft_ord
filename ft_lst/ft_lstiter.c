/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heinfalt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/26 15:49:12 by heinfalt          #+#    #+#             */
/*   Updated: 2016/11/26 15:49:13 by heinfalt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

void		ft_lstiter(t_list **alst, void (*f)(t_list *elem))
{
	t_list	*head;

	if (!alst || !(head = *alst))
		return ;
	while (head)
	{
		(*f)(head);
		head = head->next;
	}
}
