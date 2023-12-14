/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   a_to_b.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omfelk <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 12:26:47 by omfelk            #+#    #+#             */
/*   Updated: 2023/12/13 22:36:58 by omfelk           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	push_in_b(t_list **lst_a, t_list **lst_b)
{
	t_instrs	*instruction;
	int			nb_lst;

	instruction = malloc(sizeof(t_instrs));
	if (!instruction)
		return ;
	nb_lst = len_lst((*lst_a));
	pb(lst_a, lst_b);
	pb(lst_a, lst_b);
	// if((*lst_b)->nb < (*lst_b)->next->nb)
	// 	sb(lst_b, true);
	while (nb_lst-- > 2)
	{
		instrs_places(lst_a, lst_b, &instruction);
// printf("nb b %d\n", instruction->nb_b);
// printf("short b %d\n", instruction->shorts_up_b);
// printf("nb a %d\n", instruction->nb_a);
// printf("short a %d\n", instruction->shorts_up_a);
// affiche_stack(*lst_a, *lst_b);
		gest_shorts_for_b(lst_a, lst_b, &instruction);
	}
	the_end_for_b(lst_b);
	free(instruction);
}

void	instrs_places(t_list **lst_a, t_list **lst_b, t_instrs **instruction)
{
	t_list	*tmp_b;
	int		tmp_count;

	pre_add_pose(lst_a, lst_b);
	tmp_b = (*lst_b);
	tmp_count = closer_for_b(lst_a, &tmp_b, min_nb(lst_b), max(lst_b));
//printf("tmp_count %d\n", tmp_count);
	rempl_instrs_for_b(lst_a, lst_b, tmp_count, instruction);
}

int	closer_for_b(t_list **lst_a, t_list **lst_b, int min_lst_b, int max_lst_b)
{
	t_list		*tmp_b;

	tmp_b = (*lst_b);
	if ((*lst_a)->nb < max_lst_b && (*lst_a)->nb > min_lst_b)
	{
		if ((*lst_a)->nb > 0)
		{
			brows_lst_for_b(lst_a, &tmp_b);
// printf("ok\n");
		}
		else
		{
			while ((*lst_a)->nb > tmp_b->nb && tmp_b->next)
				tmp_b = tmp_b->next;
			while ((*lst_a)->nb < tmp_b->nb && tmp_b->next)
				tmp_b = tmp_b->next;
		}
		return (tmp_b->nb);
	}
	else if ((*lst_a)->nb > max_lst_b)
		return (max_lst_b);
	else if ((*lst_a)->nb < min_lst_b)
		return (min_lst_b);
	return (tmp_b->nb);
}

void	brows_lst_for_b(t_list **lst_a, t_list **lst_b)
{
// printf("a %d\n", (*lst_a)->nb);
// printf("b %d\n", (*lst_b)->nb);
	if ((*lst_a)->nb > 0)
	{
		if ((*lst_a)->nb > (*lst_b)->nb)
		{
			while (((*lst_a)->nb > (*lst_b)->nb
					|| (*lst_b)->nb < 0) && (*lst_b)->next)
				(*lst_b) = (*lst_b)->next;
			while (((*lst_a)->nb < (*lst_b)->nb && (*lst_b)->next))
				(*lst_b) = (*lst_b)->next;
		}
		else if ((*lst_a)->nb < (*lst_b)->nb)
		{
			while ((*lst_a)->nb < (*lst_b)->nb && (*lst_b)->next)
				(*lst_b) = (*lst_b)->next;
			// while (((*lst_a)->nb > (*lst_b)->nb
			// 		|| (*lst_b)->nb < 0) && (*lst_b)->next)
			// 	(*lst_b) = (*lst_b)->next;
		}
	}
}

void	rempl_instrs_for_b(t_list **lst_a, t_list **lst_b, int count,
						t_instrs **instrs)
{
	t_list	*tmp_b;

	tmp_b = (*lst_b);
	while (tmp_b->nb != count)
		tmp_b = tmp_b->next;
	(*instrs)->nb_b = tmp_b->nb;
	(*instrs)->pose_b = tmp_b->pose;
	(*instrs)->shorts_up_b = tmp_b->shorts_up;
	(*instrs)->nb_a = (*lst_a)->nb;
	(*instrs)->pose_a = (*lst_a)->pose;
	(*instrs)->shorts_up_a = (*lst_a)->shorts_up;
	(*instrs)->scor = scor_shorts_up(&tmp_b, lst_a);
}