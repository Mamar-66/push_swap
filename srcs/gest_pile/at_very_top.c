/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   at_very_top.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omfelk <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 11:33:12 by omfelk            #+#    #+#             */
/*   Updated: 2023/12/15 16:07:35 by omfelk           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	add_very_top(t_list **lst_a, t_list **lst_b)
{
	t_instrs	*instruction;

	instruction = malloc(sizeof(t_instrs));
	if (!instruction)
		return ;
	while ((*lst_b))
	{
		nb_closer(lst_a, lst_b, &instruction);
		gest_shorts(lst_a, lst_b, &instruction);
		pre_add_pose(lst_a, lst_b);
	}
	free(instruction);
}

void	nb_closer(t_list **lst_a, t_list **lst_b, t_instrs **instruction)
{
	t_list		*tmp_a;
	t_list		*tmp_aa;
	t_list		*tmp_b;
	int			tmp_count;
	int			tmp_scor;

	pre_add_pose(lst_a, lst_b);
	tmp_a = (*lst_a);
	(*instruction)->scor = 2147483647;
	while (tmp_a)
	{
		tmp_b = (*lst_b);
		while (tmp_b)
		{
			tmp_aa = (*lst_a);
			tmp_count = closer(lst_a, &tmp_b, min_nb(lst_a), max(lst_a));
			while (tmp_aa->nb != tmp_count)
				tmp_aa = tmp_aa->next;
			tmp_scor = scor_shorts_up(&tmp_aa, &tmp_b);
			if (tmp_scor < (*instruction)->scor)
				rempl_instrs(lst_a, &tmp_b, tmp_count, instruction);
			tmp_b = tmp_b->next;
		}
		tmp_a = tmp_a->next;
	}
}

void	rempl_instrs(t_list **lst_a, t_list **lst_b, int count,
					t_instrs **instrs)
{
	t_list	*tmp_a;

	tmp_a = (*lst_a);
	while (tmp_a->nb != count)
		tmp_a = tmp_a->next;
	(*instrs)->nb_a = tmp_a->nb;
	(*instrs)->pose_a = tmp_a->pose;
	(*instrs)->shorts_up_a = tmp_a->shorts_up;
	(*instrs)->nb_b = (*lst_b)->nb;
	(*instrs)->pose_b = (*lst_b)->pose;
	(*instrs)->shorts_up_b = (*lst_b)->shorts_up;
	(*instrs)->scor = scor_shorts_up(&tmp_a, lst_b);
}

int	closer(t_list **lst_a, t_list **lst_b, int min_lst_a, int max_lst_a)
{
	t_list		*tmp_a;

	tmp_a = (*lst_a);
	if ((*lst_b)->nb < max_lst_a && (*lst_b)->nb > min_lst_a)
	{
		if ((*lst_b)->nb > 0)
			brows_lst(&tmp_a, lst_b);
		else
		{
			while ((*lst_b)->nb < tmp_a->nb && tmp_a->next)
				tmp_a = tmp_a->next;
			while ((*lst_b)->nb > tmp_a->nb && tmp_a->next)
				tmp_a = tmp_a->next;
		}
		return (tmp_a->nb);
	}
	else if ((*lst_b)->nb > max_lst_a)
		return (max_lst_a);
	else if ((*lst_b)->nb < min_lst_a)
		return (min_lst_a);
	return (tmp_a->nb);
}

void	brows_lst(t_list **lst_a, t_list **lst_b)
{
	if ((*lst_b)->nb > 0)
	{
		if ((*lst_b)->nb > (*lst_a)->nb)
		{
			while (((*lst_b)->nb > (*lst_a)->nb
					|| (*lst_a)->nb < 0) && (*lst_a)->next)
				(*lst_a) = (*lst_a)->next;
		}
		else if ((*lst_b)->nb < (*lst_a)->nb)
		{
			while ((*lst_b)->nb < (*lst_a)->nb && (*lst_a)->next)
				(*lst_a) = (*lst_a)->next;
			while (((*lst_b)->nb > (*lst_a)->nb
					|| (*lst_a)->nb < 0) && (*lst_a)->next)
				(*lst_a) = (*lst_a)->next;
		}
	}
}
