/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omfelk <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 12:37:01 by omfelk            #+#    #+#             */
/*   Updated: 2023/12/19 12:12:05 by omfelk           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"
#include "../includes/bonus_push_swap.h"
#include "../includes/get_next_line.h"

int	main(int argc, char **argv)
{
	t_list		*stack_a;
	t_list		*stack_b;
	bool		ok_or_ko;

	stack_a = NULL;
	stack_b = NULL;
	if (argc >= 2 && !is_not_digit(argv))
	{
		stack_gest(&stack_a, argc, argv);
		if (is_double(&stack_a) || cmp(stack_a))
		{
			free_node(&stack_a);
			exit (1);
		}
		ok_or_ko = gest_stacks(&stack_a, &stack_b);
		if (!ok_or_ko || stack_b != NULL)
			ft_putstr("KO\n");
		else
			ft_putstr("OK\n");
	}
	free_node(&stack_a);
	free_node(&stack_b);
	return (1);
}

void	free_node(t_list **lst)
{
	t_list	*tmp;

	tmp = (*lst);
	while (tmp)
	{
		tmp = (*lst)->next;
		free(*lst);
		(*lst) = tmp;
	}
}

void	affiche_stack(t_list *stack_a, t_list *stack_b)
{
	while ((stack_a))
	{
		printf("shots up = %d stack_a pose = %d : vale = %d\n",
			stack_a->shorts_up, (stack_a)->pose, (stack_a)->nb);
		stack_a = (stack_a)->next;
	}
	printf("\n");
	while ((stack_b))
	{
		printf("             shots up = %d stack_b pose = %d : vale = %d\n",
			stack_b->shorts_up, (stack_b)->pose, (stack_b)->nb);
		stack_b = (stack_b)->next;
	}
}
