/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rang_in_stach_a.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omfelk <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 21:36:27 by omfelk            #+#    #+#             */
/*   Updated: 2023/12/12 16:17:37 by omfelk           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	gest_shorts(t_list **lst_a, t_list **lst_b, instrs **lst_instrs)
{
	while ((*lst_instrs)->pose_a != 0 || (*lst_instrs)->pose_b != 0)
	{
		pre_add_pose(lst_a, lst_b);
		// if (!up_a_and_up_b(lst_a, lst_b, lst_instrs))
		// {
			up_a(lst_a, lst_instrs);
			up_b(lst_b, lst_instrs);
		// }
	}
	pa(lst_b, lst_a);
	if ((*lst_a)->nb > (*lst_a)->next->nb)
		sa(lst_a, true);
}
bool	up_a_and_up_b(t_list **lst_a, t_list **lst_b, instrs **lst_instrs)
{
	if ((*lst_instrs)->pose_a == 0 && (*lst_instrs)->pose_b == 0)
		return (true);
	if ((*lst_instrs)->pose_a < 0 && (*lst_instrs)->pose_b < 0)
	{
		(*lst_instrs)->pose_a--;
		(*lst_instrs)->pose_b--;
		rrr(lst_a, lst_b);
		return (true);
	}
	else if((*lst_instrs)->pose_a > 0 && (*lst_instrs)->pose_b > 0)
	{
		(*lst_instrs)->pose_a++;
		(*lst_instrs)->pose_b++;
		rr(lst_a, lst_b);
		return (true);
	}
	return (false);
}

void	up_b(t_list **lst_b, instrs **lst_instrs)
{
	if ((*lst_instrs)->pose_b == 0)
		return;
	if ((*lst_instrs)->pose_b < 0)
	{
		(*lst_instrs)->pose_b++;
		rrb(lst_b, true);
	}
	else if ((*lst_instrs)->pose_b > 0)
	{
		(*lst_instrs)->pose_b--;
		rb(lst_b, true);
	}
}

void	up_a(t_list **lst_a, instrs **lst_instrs)
{
	if ((*lst_instrs)->pose_a == 0)
		return;
	if ((*lst_instrs)->pose_a < 0)
	{
		rra(lst_a, true);
		(*lst_instrs)->pose_a++;
	}
	else if ((*lst_instrs)->pose_a > 0)
	{
		(*lst_instrs)->pose_a--;
		ra(lst_a, true);
	}
}
