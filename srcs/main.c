/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omfelk <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 12:11:55 by omfelk            #+#    #+#             */
/*   Updated: 2023/11/29 18:09:05 by omfelk           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	main(int argc, char **argv)
{
	t_list	*stack_a;
	// t_list	**stack_b;

	stack_a = NULL;
	if (argc == 2 && !is_not_digit(argv[1]))
	{
		stack_gest(&stack_a, argv[1]);
		while (stack_a)
		{
printf("stack_ a %d\n", stack_a->nb);
			stack_a = stack_a->next;
		}
	}
	free(stack_a);
	return (0);
}
