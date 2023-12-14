/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rang_in_stach_a.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omfelk <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 21:36:27 by omfelk            #+#    #+#             */
/*   Updated: 2023/12/14 13:54:56 by omfelk           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	gest_shorts(t_list **lst_a, t_list **lst_b, t_instrs **lst_instrs)
{
	bool	short_a;
	bool	short_b;

	short_a = false;
	short_b = false;
	while (!short_a || !short_b)
	{
		if ((*lst_instrs)->nb_b > (*lst_instrs)->nb_a
			&& (*lst_instrs)->shorts_up_a == -1)
			short_a = true;
		if ((*lst_instrs)->nb_b < (*lst_instrs)->nb_a
			&& (*lst_instrs)->shorts_up_a == 0)
			short_a = true;
		if ((*lst_instrs)->shorts_up_b == 0)
			short_b = true;
		if (!up_a_and_up_b(lst_a, lst_b, lst_instrs))
		{
			if (!short_a)
				up_a(lst_a, lst_instrs);
			if (!short_b)
				up_b(lst_b, lst_instrs);
		}
	}
	pa(lst_b, lst_a);
}

bool	up_a_and_up_b(t_list **lst_a, t_list **lst_b, t_instrs **lst_instrs)
{
	if ((*lst_instrs)->nb_b > (*lst_instrs)->nb_a)
	{
		if ((*lst_instrs)->shorts_up_a < -1 && (*lst_instrs)->shorts_up_b < 0)
		{
			(*lst_instrs)->shorts_up_a++;
			(*lst_instrs)->shorts_up_b++;
			rrr(lst_a, lst_b);
			return (true);
		}
	}
	else if ((*lst_instrs)->shorts_up_a < 0 && (*lst_instrs)->shorts_up_b < 0)
	{
		(*lst_instrs)->shorts_up_a++;
		(*lst_instrs)->shorts_up_b++;
		rrr(lst_a, lst_b);
		return (true);
	}
	else if ((*lst_instrs)->shorts_up_a > 0 && (*lst_instrs)->shorts_up_b > 0)
	{
		(*lst_instrs)->shorts_up_a--;
		(*lst_instrs)->shorts_up_b--;
		rr(lst_a, lst_b);
		return (true);
	}
	return (false);
}

void	up_b(t_list **lst_b, t_instrs **lst_instrs)
{
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

void	up_a(t_list **lst_a, t_instrs **lst_instrs)
{
	if ((*lst_instrs)->shorts_up_a < 0)
	{
		rra(lst_a, true);
		(*lst_instrs)->shorts_up_a++;
	}
	else if ((*lst_instrs)->shorts_up_a >= 0)
	{
		(*lst_instrs)->shorts_up_a--;
		ra(lst_a, true);
	}
}
