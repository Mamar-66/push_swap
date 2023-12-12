/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_pose.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omfelk <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 11:20:29 by omfelk            #+#    #+#             */
/*   Updated: 2023/12/11 13:12:32 by omfelk           ###   ########.fr       */
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
	i = 0;
	size = len_lst(*lst);
	i_shots = 0;
	while (tmp)
	{
		tmp->pose = i;
		if (i <= size / 2)
			tmp->shorts_up = i_shots++;
		if (i == size / 2 && size % 2 == 0)
			i_shots--;
		if (i > size / 2)
			tmp->shorts_up = --i_shots * -1;
		tmp = tmp->next;
		i++;
	}
}
