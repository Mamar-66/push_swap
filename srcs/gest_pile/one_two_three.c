/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   one_two_three.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omfelk <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 15:52:11 by omfelk            #+#    #+#             */
/*   Updated: 2023/12/04 18:00:43 by omfelk           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	one_two_three_n(t_list **lst)
{
	while (!(cmp(*lst)))
	{
		if (len_lst((*lst)) == 3)
		{
			if ((*lst)->next->nb < (*lst)->next->next->nb)
				ra(lst, true);
			else 
				rra(lst, true);
		}
		if ((*lst)->nb > 0 && (*lst)->nb > (*lst)->next->nb)
				sa(lst, true);
		else if ((*lst)->nb > (*lst)->next->nb)
			sa(lst, true);
	}
}
