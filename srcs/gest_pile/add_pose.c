/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_pose.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omfelk <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 11:20:29 by omfelk            #+#    #+#             */
/*   Updated: 2023/12/06 17:14:27 by omfelk           ###   ########.fr       */
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

	tmp = (*lst);
	i = 0;
	while ((*lst))
	{
		(*lst)->pose = i;
		(*lst) = (*lst)->next;
		i++;
	}
	(*lst) = tmp;
}
