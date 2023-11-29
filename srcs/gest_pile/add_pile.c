/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_pile.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omfelk <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 19:42:39 by omfelk            #+#    #+#             */
/*   Updated: 2023/11/27 21:23:38 by omfelk           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

char	*word_nb(char *str, int *start)
{
	char	*nb_str;
	int		i;
	int		j;
	int		k;

	i = *start;
	j = 0;
	k = 0;
	while (str[i])
	{
		while (str[i] != ' ' && str[i] != '\t')
			i++;
		while (str[i] >= '0' && str[i++] <= '9')
			j++;
		if (j == 0)
			return (NULL);
		nb_str = ft_calloc(sizeof(char), j + 1);
		if (!nb_str)
			return (NULL);
		i -= j;
		while (k <= j)
			nb_str[k++] = str[i++];
		*start = i;
	}
	return (nb_str);
}

// t_list	add_stack(char *str)
// {
// 	int		i;
// 	t_list	stack;

// 	i = 0;
// 	while (str[i])
// 	{

// 	}
// }
