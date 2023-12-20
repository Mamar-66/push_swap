/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gest_stacks.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omfelk <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 11:38:03 by omfelk            #+#    #+#             */
/*   Updated: 2023/12/19 12:26:43 by omfelk           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"
#include "../includes/bonus_push_swap.h"
#include "../includes/get_next_line.h"

bool	gest_stacks(t_list **lst_a, t_list **lst_b)
{
	char	*string;

	string = get_next_line(STDIN_FILENO);
	while (string != NULL)
	{
		if (practical(lst_a, lst_b, string) == false)
		{
			ft_putstr("command not found\n");
			free(string);
			exit (1);
		}
		free(string);
		string = get_next_line(STDIN_FILENO);
	}
	return (cmp(*lst_a));
}

bool	practical(t_list **lst_a, t_list **lst_b, char *action)
{
	if (ft_strcmp(action, "sa"))
		sa(lst_a, false);
	else if (ft_strcmp(action, "sb"))
		sb(lst_b, false);
	else if (ft_strcmp(action, "ss"))
		ss(lst_a, lst_b);
	else if (ft_strcmp(action, "pa"))
		pa(lst_b, lst_a);
	else if (ft_strcmp(action, "pb"))
		pb(lst_a, lst_b);
	else if (ft_strcmp(action, "ra"))
		ra(lst_a, false);
	else if (ft_strcmp(action, "rb"))
		rb(lst_b, false);
	else if (ft_strcmp(action, "rr"))
		rr(lst_a, lst_b);
	else if (ft_strcmp(action, "rra"))
		rra(lst_a, false);
	else if (ft_strcmp(action, "rrb"))
		rrb(lst_b, false);
	else if (ft_strcmp(action, "rrr"))
		rrr(lst_a, lst_b);
	else
		return (false);
	return (true);
}
