/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pa_pb.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omfelk <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 10:01:47 by omfelk            #+#    #+#             */
/*   Updated: 2023/12/01 12:05:08 by omfelk           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/push_swap.h"

void	pa(t_list **src, t_list **dest)
{
	t_list	*tmp;

	if (!(*src))
		return ;
	tmp = (*src)->next;
	(*src)->next = (*dest);
	(*dest) = (*src);
	(*src) = tmp;
	ft_putstr("pa\n");
}

void	pb(t_list **src, t_list **dest)
{
	t_list	*tmp;

	if (!(*src))
		return ;
	tmp = (*src)->next;
	(*src)->next = (*dest);
	(*dest) = (*src);
	(*src) = tmp;
	ft_putstr("pb\n");
}
