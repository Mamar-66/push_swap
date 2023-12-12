/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   at_very_top.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omfelk <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 11:33:12 by omfelk            #+#    #+#             */
/*   Updated: 2023/12/12 17:43:20 by omfelk           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	add_very_top(t_list **lst_a, t_list **lst_b)
{
	instrs	*instruction;

	instruction = malloc(sizeof(instrs));
	if (!instruction)
		return ;
	while ((*lst_b))
	{
		pre_add_pose(lst_a, lst_b);
affiche_stack(*lst_a, *lst_b);
		nb_closer(lst_a, lst_b, &instruction);
printf("lst nb a = %d\n", (instruction)->nb_a);
printf("lst pose a = %d\n", (instruction)->pose_a);
printf("lst nb b = %d\n", (instruction)->nb_b);
printf("lst pose b = %d\n", (instruction)->pose_b);
printf("le scor = %d\n", (instruction)->scor);
printf("le way = %d\n", (instruction)->way);
		gest_shorts(lst_a, lst_b, &instruction);
		//pa(lst_b, lst_a);
	}
	free(instruction);
//-810 164 589 195 133 -393 -481 928 444 -922 387 702 -274 708 -431 560 -547 -311 327 -851
}

int	nb_closer(t_list **lst_a, t_list **lst_b, instrs **instruction)
{
	t_list		*tmp_a;
	t_list		*tmp_b;
	int			tmp_count;
	int			tmp_scor;

	pre_add_pose(lst_a, lst_b);
	tmp_a = (*lst_a);
//(*instruction)->min_c = 2147483647;
	(*instruction)->scor = 2147483647;
	while (tmp_a->next)
	{
		tmp_b = (*lst_b);
		while (tmp_b)
		{
			tmp_count = closer(lst_a, &tmp_b, min_nb(lst_a), max(lst_a));
			tmp_scor = scor_shorts_up(&tmp_a, &tmp_b);
			if (tmp_scor < (*instruction)->scor)
				rempl_instrs(lst_a, &tmp_b, tmp_count, instruction);
			tmp_b = tmp_b->next;
		}
		tmp_a = tmp_a->next;
	}
	return (1);
}

int	closer(t_list **lst_a, t_list **lst_b, int min_lst_a, int max_lst_a)
{
	t_list		*tmp_a;

	tmp_a = (*lst_a);
	if ((*lst_b)->nb < max_lst_a && (*lst_b)->nb > min_lst_a)
	{
		if ((*lst_b)->nb > tmp_a->nb)
			return (tmp_a->next->nb);
		if ((*lst_b)->nb > 0)
		{
			while (((*lst_b)->nb < tmp_a->nb || tmp_a->nb < 0) && tmp_a->next)
				tmp_a = tmp_a->next;
		}
		else
		{
			while ((*lst_b)->nb < tmp_a->nb && tmp_a)
				tmp_a = tmp_a->next;
		}
		return (tmp_a->nb);
	}
	else if ((*lst_b)->nb > max_lst_a)
		return (max_lst_a);
	else if ((*lst_b)->nb < min_lst_a)
		return (min_lst_a);
	return (0);
}

void	rempl_instrs(t_list **lst_a, t_list **lst_b, int count, instrs **instrs)
{
	t_list	*tmp_a;

	tmp_a = (*lst_a);
	while (tmp_a->nb != count)
		tmp_a = tmp_a->next;
	(*instrs)->nb_a = tmp_a->nb;
	(*instrs)->pose_a = tmp_a->pose;
	(*instrs)->shorts_up_a = tmp_a->shorts_up;
	(*instrs)->nb_b = (*lst_b)->nb;
	(*instrs)->pose_b = (*lst_b)->pose;
	(*instrs)->shorts_up_b = (*lst_b)->shorts_up;
	(*instrs)->scor = scor_shorts_up(&tmp_a, lst_b);
}

int	scor_shorts_up(t_list **lst_a, t_list **lst_b)
{
	int	shorts_up_a;
	int	shorts_up_b;

	shorts_up_a = (*lst_a)->shorts_up;
	shorts_up_b = (*lst_b)->shorts_up;
	if (shorts_up_a < 0)
		shorts_up_a = shorts_up_a * -1;
	if (shorts_up_b < 0)
		shorts_up_b = shorts_up_b * -1;
	return (shorts_up_a + shorts_up_b);
}
/* 	(*instrs)->min_c = count;
	(*instrs)->nb_a = (*lst_a)->nb;
	(*instrs)->pose_a = (*lst_a)->pose;
	(*instrs)->shorts_up_a = (*lst_a)->shorts_up;
	(*instrs)->nb_b = (*lst_b)->nb;
	(*instrs)->pose_b = (*lst_b)->pose;
	(*instrs)->shorts_up_b = (*lst_b)->shorts_up;
	(*instrs)->scor = scor_shorts_up(lst_a, lst_b); */

/* //||((*lst_b)->nb < (*lst_a)->nb && (*lst_b)->nb > (*lst_a)->next->nb)
	if (((*lst_b)->nb > (*lst_a)->nb && (*lst_b)->nb < (*lst_a)->next->nb)
		|| ((*lst_b)->nb < (*lst_a)->nb && (*lst_b)->nb > (*lst_a)->next->nb))
		tmp_count = 2;
	else if (((*lst_b)->nb < (*lst_a)->nb && (*lst_a)->nb == max_lst_a) ||
			((*lst_b)->nb > (*lst_a)->nb && (*lst_a)->nb == min_lst_a))
		tmp_count = 3;
	// else if ((*lst_b)->nb > tmp_a->nb && (*lst_b)->nb < tmp_a->next->nb)
	// 	tmp_count = 1;
	else
		tmp_count = -1; */