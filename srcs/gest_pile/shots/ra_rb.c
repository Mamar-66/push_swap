/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ra_rb.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omfelk <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 17:18:12 by omfelk            #+#    #+#             */
/*   Updated: 2023/12/01 11:32:40 by omfelk           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/push_swap.h"

void	ra(t_list **lst)
{
	t_list	*tmp;
	int		swap;
	if (!(*lst))
		return ;
	tmp = *lst;
	while ((*lst)->next)
	{
		swap = (*lst)->nb;
		(*lst)->nb = (*lst)->next->nb;
		(*lst)->next->nb = swap;
		(*lst) = (*lst)->next;
	}
	(*lst) = tmp;
	ft_putstr("ra\n");
}

void	rb(t_list **lst)
{
	t_list	*tmp;
	int		swap;

	if (!(*lst))
		return ;
	tmp = *lst;
	while ((*lst)->next)
	{
		swap = (*lst)->nb;
		(*lst)->nb = (*lst)->next->nb;
		(*lst)->next->nb = swap;
		(*lst) = (*lst)->next;
	}
	(*lst) = tmp;
	ft_putstr("rb\n");
}
