/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ss.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omfelk <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 16:55:46 by omfelk            #+#    #+#             */
/*   Updated: 2023/12/04 16:23:15 by omfelk           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/push_swap.h"

void	ss(t_list **lst_a, t_list **lst_b)
{
	bool	write;

	write = false;
	if (!(*lst_a)->next || !(*lst_b)->next)
		return ;
	sa(lst_a, write);
	sb(lst_b, write);
}
