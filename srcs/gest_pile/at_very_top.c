/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   at_very_top.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omfelk <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 11:33:12 by omfelk            #+#    #+#             */
/*   Updated: 2023/12/06 17:38:52 by omfelk           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	add_very_top(t_list **lst_a, t_list **lst_b)
{
	put_everything_in_stack_a(lst_a, lst_b);
}

void	put_everything_in_stack_a(t_list **lst_a, t_list **lst_b)
{
	int		size_lst;
	int		pose_closer;

	while ((*lst_b))
	{
		pose_closer = nb_closer(lst_a, lst_b);
		size_lst = len_lst(*lst_a);
		if (pose_closer > size_lst / 2)
		{
			while (pose_closer != (*lst_a)->pose)
				rra(lst_a, true);
			pa(lst_b, lst_a);
		}
		else
		{
			while (pose_closer != (*lst_a)->pose)
				ra(lst_a, true);
			pa(lst_b, lst_a);
		}
	}
}

int	nb_closer(t_list **lst_a, t_list **lst_b)
{
	t_list	*tmp;
	int		closer;
	int		nb_max;
	int		tmp_count;
	int		min_count[2];

	pre_add_pose(lst_a, lst_b);
	nb_max = max(lst_a);
	tmp = (*lst_a);
	min_count[0] = 1500;
	while (tmp)
	{
		closer = (*lst_b)->nb;
		tmp_count = 0;
		while (closer != tmp->nb && closer++ <= nb_max)
			tmp_count++;
		if (min_count[0] > tmp_count)
		{
			min_count[0] = tmp_count;
			min_count[1] = tmp->pose;
		}
		tmp = tmp->next;
	}
	return (min_count[1]);
}

int	nb_closer_b(t_list **lst_a, t_list **lst_b)
{
	t_list	*tmp_b;
	int		closer_tmp;
	int		closer;
	int		pose;

	tmp_b = (*lst_b);
	closer = 1500;
	pose = 0;
	while (tmp_b)
	{
		closer_tmp = nb_closer(lst_a, &tmp_b);
		if (closer > closer_tmp)
		{
			closer = closer_tmp;
			pose = tmp_b->pose;
		}
		tmp_b = tmp_b->next;
	}
printf("fille b %d\n", pose);
	return (pose);
}
