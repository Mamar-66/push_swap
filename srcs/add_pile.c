/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_pile.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omfelk <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 19:42:39 by omfelk            #+#    #+#             */
/*   Updated: 2023/11/29 12:34:56 by omfelk           ###   ########.fr       */
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
	while ((str[i] == ' ' || str[i] == '\t') && str[i])
		i++;
	while ((str[i] >= '0' && str[i] <= '9' && str[i]) || (str[i] == '-' && str[i]))
	{
		i++;
		j++;
	}
	if (j == 0)
		return (NULL);
	nb_str = ft_calloc(sizeof(char), j + 1);
	if (!nb_str)
		return (NULL);
	i -= j;
	while (k < j)
		nb_str[k++] = str[i++];
	*start = i;
	return (nb_str);
}

void	add_stack(t_list *lst, char *argv_str)
{
	t_list	*lst_new;
	int		start;
	char	*str;

	start = 0;
	lst_new = (t_list *)malloc(sizeof(t_list));
	str = word_nb(argv_str, &start);
	while (lst->next)
		lst = lst->next;
	lst->nb =  ft_atoi(str);
	lst->next = lst_new;
	lst_new->next = NULL;
}
