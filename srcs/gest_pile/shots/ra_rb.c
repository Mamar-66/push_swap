/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ra.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omfelk <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 17:18:12 by omfelk            #+#    #+#             */
/*   Updated: 2023/11/30 17:33:08 by omfelk           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/push_swap.h"

void	ra_rb(t_list **lst)
{
	t_list	*tmp;
	int		swap;

	tmp = *lst;
	while ((*lst)->next)
	{
		swap = (*lst)->nb;
		(*lst)->nb = (*lst)->next->nb;
		(*lst)->next->nb = swap;
		(*lst) = (*lst)->next;
	}
	(*lst) = tmp;
}
