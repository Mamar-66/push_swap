/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omfelk <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 12:11:55 by omfelk            #+#    #+#             */
/*   Updated: 2023/11/29 12:35:02 by omfelk           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	main(int argc, char **argv)
{
	t_list	**stack_a;
	// t_list	**stack_b;

	stack_a = (t_list **)malloc(sizeof(t_list));
	if (argc == 2 && !is_not_digit(argv[1]))
	{
printf("ok\n");
		add_stack(*stack_a, argv[1]);
//printf("%d\n", (*stack_a)->nb);
	}
	free(stack_a);
	return (0);
}
