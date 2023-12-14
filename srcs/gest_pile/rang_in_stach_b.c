/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rang_in_stach_b.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omfelk <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 21:36:27 by omfelk            #+#    #+#             */
/*   Updated: 2023/12/13 21:10:00 by omfelk           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	gest_shorts_for_b(t_list **lst_a, t_list **lst_b, t_instrs **lst_instrs)
{
	// int	size;

	// size = len_lst(*lst_b);
	(void)lst_a;
	pre_add_pose(lst_a, lst_b);
	while ((*lst_instrs)->shorts_up_b != 0)
	{
		down_b(lst_b, lst_instrs, 10);
	}
	pb(lst_a, lst_b);
	if ((*lst_b)->nb < (*lst_b)->next->nb)
		sb(lst_b, true);
}

void	down_b(t_list **lst_b, t_instrs **lst_instrs, int size)
{
	(void)size;
	if ((*lst_instrs)->shorts_up_b == 0)
		return ;
	if ((*lst_instrs)->shorts_up_b < 0)
	{
		rrb(lst_b, true);
		(*lst_instrs)->shorts_up_b++;
	}
	else if ((*lst_instrs)->shorts_up_b > 0)
	{
		(*lst_instrs)->shorts_up_b--;
		rb(lst_b, true);
	}
}

void	the_end_for_b(t_list **lst)
{
	t_list	*tmp_b;
	int		nb_max;
	pre_add_pose(lst, lst);
	tmp_b = (*lst);
	nb_max = max(lst);
	while (tmp_b->nb != nb_max)
		tmp_b = tmp_b->next;
	if (tmp_b->shorts_up > 0)
	{
		while ((*lst)->nb != nb_max)
			rrb(lst, true);
	}
	else if (tmp_b->shorts_up < 0)
	{
		while ((*lst)->nb != nb_max)
			rb(lst, true);
	}
}
