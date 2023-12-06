/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ra_rb.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omfelk <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 17:18:12 by omfelk            #+#    #+#             */
/*   Updated: 2023/12/06 16:34:33 by omfelk           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/push_swap.h"

void	ra(t_list **lst, bool write)
{
	t_list	*head;
	t_list	*tail;

	if (!(*lst))
		return ;
	head = (*lst);
	while ((*lst)->next)
		(*lst) = (*lst)->next;
	tail = (*lst);
	(*lst) = head->next;
	head->next = NULL;
	tail->next = head;
	if (write)
		ft_putstr("ra\n");
}

void	rb(t_list **lst, bool write)
{
	t_list	*head;
	t_list	*tail;

	if (!(*lst))
		return ;
	head = (*lst);
	while ((*lst)->next)
		(*lst) = (*lst)->next;
	tail = (*lst);
	(*lst) = head->next;
	head->next = NULL;
	tail->next = head;
	if (write)
		ft_putstr("rb\n");
}
