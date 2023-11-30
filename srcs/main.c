/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omfelk <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 12:11:55 by omfelk            #+#    #+#             */
/*   Updated: 2023/11/30 16:59:19 by omfelk           ###   ########.fr       */
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
	if (argc == 3 && !is_not_digit(argv[1]))
	{
		stack_gest(&stack_a, argv[1]);
		stack_gest(&stack_b, argv[2]);
		if (is_double(&stack_a))
			exit (1);
		affiche_stack(stack_a, stack_b);
		ss(&stack_a, &stack_b);
printf("\n");
		affiche_stack(stack_a, stack_b);
	}
	free(stack_a);
	return (0);
}

void	affiche_stack(t_list *stack_a, t_list *stack_b)
{
	while ((stack_a))
	{
		printf("stack_a : %d\n", (stack_a)->nb);
		stack_a = (stack_a)->next;
	}
	while ((stack_b))
	{
		printf("             stack_b : %d\n", (stack_b)->nb);
		stack_b = (stack_b)->next;
	}
}
