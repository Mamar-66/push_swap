/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sa_sb.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omfelk <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 16:06:44 by omfelk            #+#    #+#             */
/*   Updated: 2023/12/05 12:56:34 by omfelk           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/push_swap.h"

void	sa(t_list **lst, bool write)
{
	int		nb;
	int		pose;

	if (!(*lst) || !(*lst)->next)
		return ;
	nb = (*lst)->nb;
	pose = (*lst)->pose;
	(*lst)->nb = (*lst)->next->nb;
	(*lst)->pose = (*lst)->next->pose;
	(*lst)->next->nb = nb;
	(*lst)->next->pose = pose;
	if (write)
		ft_putstr("sa\n");
}

void	sb(t_list **lst, bool write)
{
	int		nb;
	int		pose;

	if (!(*lst) || !(*lst)->next)
		return ;
	nb = (*lst)->nb;
	pose = (*lst)->pose;
	(*lst)->nb = (*lst)->next->nb;
	(*lst)->pose = (*lst)->next->pose;
	(*lst)->next->nb = nb;
	(*lst)->next->pose = pose;
	if (write)
		ft_putstr("sb\n");
}
