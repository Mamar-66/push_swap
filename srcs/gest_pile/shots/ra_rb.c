/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ra_rb.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omfelk <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 17:18:12 by omfelk            #+#    #+#             */
/*   Updated: 2023/12/01 15:15:46 by omfelk           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/push_swap.h"

void	ra(t_list **lst, bool write)
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
	if (write)
		ft_putstr("ra\n");
}

void	rb(t_list **lst, bool write)
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
	if (write)
		ft_putstr("rb\n");
}
