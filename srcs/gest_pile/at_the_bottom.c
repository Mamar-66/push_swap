/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   at_the_bottom.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omfelk <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 11:04:04 by omfelk            #+#    #+#             */
/*   Updated: 2023/12/07 16:27:13 by omfelk           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	bottom(t_list **lst_a, t_list **lst_b)
{
	t_list		*tmp;
	int			size_lst;
	int			pose_closer;

	pose_closer = nb_closer_moin(lst_a, lst_b);
	size_lst = len_lst(*lst_a);
	tmp = (*lst_a);
//printf("closer %d\n", pose_closer);
	while (tmp->next)
		tmp = tmp->next;
//printf("%d pose  %d\n", (*lst_a)->nb, (*lst_a)->pose);
	if (pose_closer > size_lst / 2)
	{
		while (pose_closer++ > size_lst)
			rra(lst_a, true);
		pa(lst_b, lst_a);
	}
	else
	{
		while (pose_closer-- >= 0)
			ra(lst_a, true);
		pa(lst_b, lst_a);
	}
}

int	the_way(t_list **lst_a, t_list **lst_b)
{
	int		nb_max;

	nb_max = max(lst_a);
	if ((*lst_b)->nb > nb_max)
		return (-1);
	return (1);
}

int	nb_closer_moin(t_list **lst_a, t_list **lst_b)
{
	t_list	*tmp;
	int		closer;
	int		max_nb;

	pre_add_pose(lst_a, lst_b);
	tmp = (*lst_a);
	max_nb = max(lst_a);
	while (tmp)
	{
		if (tmp->nb == max_nb)
			break;
		tmp = tmp->next;
	}
closer = tmp->pose;
	return (closer);
}
