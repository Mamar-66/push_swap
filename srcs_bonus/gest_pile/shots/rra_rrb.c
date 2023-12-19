/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rra_rrb.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omfelk <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 10:34:22 by omfelk            #+#    #+#             */
/*   Updated: 2023/12/01 15:59:51 by omfelk           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/push_swap.h"

void	rra(t_list **lst, bool write)
{
	t_list	*tmp;
	t_list	*last_lst;

	if (!(*lst) || !(*lst)->next)
		return ;
	tmp = (*lst);
	while ((*lst)->next->next)
		(*lst) = (*lst)->next;
	last_lst = (*lst)->next;
	(*lst)->next = NULL;
	last_lst->next = tmp;
	(*lst) = last_lst;
	if (write)
		ft_putstr("rra\n");
}

void	rrb(t_list **lst, bool write)
{
	t_list	*tmp;
	t_list	*last_lst;

	if (!(*lst) || !(*lst)->next)
		return ;
	tmp = (*lst);
	while ((*lst)->next->next)
		(*lst) = (*lst)->next;
	last_lst = (*lst)->next;
	(*lst)->next = NULL;
	last_lst->next = tmp;
	(*lst) = last_lst;
	if (write)
		ft_putstr("rrb\n");
}
