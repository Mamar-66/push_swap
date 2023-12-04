/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omfelk <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 12:11:55 by omfelk            #+#    #+#             */
/*   Updated: 2023/12/04 18:10:43 by omfelk           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	affiche_stack(t_list *stack_a, t_list *stack_b);

int	main(int argc, char **argv)
{
	t_list	*stack_a;
	t_list	*stack_b;

	stack_a = NULL;
	stack_b = NULL;
	if (argc == 2 && !is_not_digit(argv[1]))
	{
		stack_gest(&stack_a, argv[1]);
//affiche_stack(stack_a, stack_b);
		if (is_double(&stack_a))
			exit (1);
		if (len_lst(stack_a) <= 3)
			one_two_three_n(&stack_a);
//affiche_stack(stack_a, stack_b);
	}
	free(stack_a);
	free(stack_b);
	return (0);
}

void	affiche_stack(t_list *stack_a, t_list *stack_b)
{
	while ((stack_a))
	{
		printf("stack_a : %d\n", (stack_a)->nb);
		stack_a = (stack_a)->next;
	}
	printf("\n");
	while ((stack_b))
	{
		printf("             stack_b : %d\n", (stack_b)->nb);
		stack_b = (stack_b)->next;
	}
}
