/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmp.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omfelk <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 16:20:59 by omfelk            #+#    #+#             */
/*   Updated: 2023/12/04 20:12:14 by omfelk           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

bool	cmp(t_list *lst)
{
	t_list	*tmp;

	tmp = lst;
	while (lst->next)
	{
		if (lst->nb > lst->next->nb)
			return (false);
		lst = lst->next;
	}
	lst = tmp;
	return (true);
}
