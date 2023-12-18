/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_pose.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omfelk <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 11:20:29 by omfelk            #+#    #+#             */
/*   Updated: 2023/12/15 16:11:09 by omfelk           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	pre_add_pose(t_list **lst_a, t_list **lst_b)
{
	if (!lst_a)
		return ;
	add_pose(lst_a);
	if (!lst_b)
		return ;
	add_pose(lst_b);
}

void	add_pose(t_list **lst)
{
	t_list		*tmp;
	int			i;
	int			i_shots;
	int			size;

	tmp = (*lst);
	i = -1;
	size = len_lst(*lst);
	i_shots = 0;
	while (tmp)
	{
		tmp->pose = ++i;
		if (i <= size / 2)
			tmp->shorts_up = i_shots++;
		if (i == size / 2 && size % 2 == 0)
			i_shots--;
		if (i > size / 2)
			tmp->shorts_up = --i_shots * -1;
		tmp = tmp->next;
	}
}

int	scor_shorts_up(t_list **lst_a, t_list **lst_b)
{
	if ((*lst_a)->shorts_up > 0 && (*lst_b)->shorts_up > 0)
	{
		if ((*lst_a)->shorts_up > (*lst_b)->shorts_up)
			return ((*lst_a)->shorts_up);
		else
			return ((*lst_b)->shorts_up);
	}
	else if ((*lst_a)->shorts_up < 0 && (*lst_b)->shorts_up < 0)
	{
		if (((*lst_a)->shorts_up * -1) > ((*lst_b)->shorts_up * -1))
			return (((*lst_a)->shorts_up * -1));
		else
			return (((*lst_b)->shorts_up * -1));
	}
	return (next_shorts_up(lst_a, lst_b));
}

int	next_shorts_up(t_list **lst_a, t_list **lst_b)
{
	int		shorts_up_a;
	int		shorts_up_b;

	if ((*lst_a)->shorts_up > 0)
		shorts_up_a = (*lst_a)->shorts_up;
	else
		shorts_up_a = ((*lst_a)->shorts_up * -1);
	if ((*lst_b)->shorts_up > 0)
		shorts_up_b = (*lst_b)->shorts_up;
	else
		shorts_up_b = ((*lst_b)->shorts_up * -1);
	return (shorts_up_a + shorts_up_b);
}

int	next_shorts_pose_result(int lst_action, int size_action,
							int lst_subit, int size_subit)
{
	if (lst_action < size_action / 2)
	{
		while (lst_action-- > 0)
		{
			lst_subit--;
			if (lst_subit < 0)
				lst_subit = size_subit;
		}
	}
	else
	{
		while (lst_action++ <= size_action)
		{
			lst_subit++;
			if (lst_subit > size_subit)
				lst_subit = 0;
		}
	}
	if (lst_subit < size_subit / 2)
		return (lst_subit);
	else
		return (size_subit - lst_subit);
}
