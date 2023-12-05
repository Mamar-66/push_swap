/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   one_three.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omfelk <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 15:52:11 by omfelk            #+#    #+#             */
/*   Updated: 2023/12/05 11:28:58 by omfelk           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	one_three(t_list **lst)
{
	if (len_lst(*lst) == 3)
		rang(lst, max(lst));
	if ((*lst)->nb > (*lst)->next->nb)
		sa(lst, true);
}

int	max(t_list **lst)
{
	int		int_max;
	t_list	*tmp;

	tmp = (*lst);
	int_max = (*lst)->nb;
	while ((*lst))
	{
		if (int_max < (*lst)->nb)
			int_max = (*lst)->nb;
		(*lst) = (*lst)->next;
	}
	(*lst) = tmp;
	return (int_max);
}

void	rang(t_list **lst, int int_max)
{
	if (int_max == (*lst)->nb)
		ra(lst, true);
	else if (int_max == (*lst)->next->nb)
		rra(lst, true);
}
