/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   three_plus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omfelk <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 11:13:01 by omfelk            #+#    #+#             */
/*   Updated: 2023/12/07 16:48:57 by omfelk           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	three_plus(t_list **lst_a, t_list **lst_b)
{
	int		mediane;
	int		nb_lst;

	nb_lst = len_lst((*lst_a));
	mediane = find_mediane(lst_a);
printf("mediane = %d\n", mediane);
	pb(lst_a, lst_b);
	while (--nb_lst > 3)
	{
		pb(lst_a, lst_b);
		if ((*lst_b)->nb < mediane && (*lst_b)->next->nb > mediane)
			rb(lst_b, true);
	}
	one_three(lst_a);
	//add_very_top(lst_a, lst_b);
	//the_end(lst_a);
}

int	find_mediane(t_list **lst_a)
{
	t_list	*tmp;
	int		*tab_all_vall;
	int		i;
	int		med;

	i = 0;
	tmp = (*lst_a);
	tab_all_vall = malloc(sizeof(int) * len_lst((*lst_a)) + 1);
	if (!tab_all_vall)
		exit (1);
	while (tmp)
	{
		tab_all_vall[i] = tmp->nb;
		tmp = tmp->next;
		i++;
	}
	rang_tab(tab_all_vall);
	med = tab_all_vall[i / 2];
	free(tab_all_vall);
	return (med);
}

void	rang_tab(int *tab_all_vall)
{
	int	swap;
	int	i;

	i = 0;
	while (tab_all_vall[i + 1])
	{
		if (tab_all_vall[i] > tab_all_vall[i + 1])
		{
			swap = tab_all_vall[i];
			tab_all_vall[i] = tab_all_vall[i + 1];
			tab_all_vall[i + 1] = swap;
			i = 0;
		}
		else
			i++;
	}
}

void	the_end(t_list **lst)
{
	int	min;

	min = min_nb(lst);
	while ((*lst)->nb != min)
		rra(lst, true);
}

int	min_nb(t_list **lst)
{
	t_list	*tmp;
	int		min;

	tmp = (*lst);
	min = tmp->nb;
	while (tmp)
	{
		if (tmp->nb < min)
			min = tmp->nb;
		tmp = tmp->next;
	}
	return (min);
}
