/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rrr.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omfelk <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 11:04:55 by omfelk            #+#    #+#             */
/*   Updated: 2023/12/01 15:19:06 by omfelk           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/push_swap.h"

void	rrr(t_list **lst_a, t_list **lst_b)
{
	bool	write;

	write = false;
	rra(lst_a, write);
	rrb(lst_b, write);
	ft_putstr("rrr\n");
}
