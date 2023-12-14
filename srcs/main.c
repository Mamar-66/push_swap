/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omfelk <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 12:11:55 by omfelk            #+#    #+#             */
/*   Updated: 2023/12/14 23:24:03 by omfelk           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	main(int argc, char **argv)
{
	t_list	*stack_a;
	t_list	*stack_b;

	stack_a = NULL;
	stack_b = NULL;
	if (argc >= 2 && !is_not_digit(argv))
	{
		stack_gest(&stack_a, argc, argv);
		if (is_double(&stack_a) || cmp(stack_a))
			exit (1);
		// affiche_stack(stack_a, stack_b);
		if (len_lst(stack_a) <= 3)
			one_three(&stack_a);
		if (len_lst(stack_a) > 3)
			three_plus(&stack_a, &stack_b);
		// affiche_stack(stack_a, stack_b);
	}
	free(stack_a);
	free(stack_b);
	return (0);
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
