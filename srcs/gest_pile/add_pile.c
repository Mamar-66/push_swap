/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_pile.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omfelk <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 19:42:39 by omfelk            #+#    #+#             */
/*   Updated: 2023/12/04 23:43:32 by omfelk           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

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
	while ((str[i] >= '0' && str[i] <= '9' && str[i++])
		|| (str[i] == '-' && str[i++]))
		j++;
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

void	stack_gest(t_list **lst, int ac, char **argv_str)
{
	char	*str;
	int		start_tr[2];
	int		i;

	start_tr[0] = 0;
	start_tr[1] = 0;
	i = 0;
	if (word_nb(argv_str[1], &start_tr[0]))
	{
		if (!(*lst))
			*lst = (t_list *)malloc(sizeof(t_list));
		if (!*lst)
			return ;
	}
	while (++i < ac)
	{
		start_tr[0] = 0;
		while (1)
		{
			str = word_nb(argv_str[i], &start_tr[0]);
			if (!str)
				break ;
			add_stack(*lst, str, &start_tr[1]);
		}
	}
}

int	add_stack(t_list *lst, char *str, int *tr)
{
	t_list		*new_lst;

	while (lst->next)
		lst = lst->next;
	if (*tr == 0)
	{
		lst->nb = ft_atoi(str);
		*tr = 1;
	}
	else if (*tr == 1)
	{
		new_lst = (t_list *)malloc(sizeof(t_list));
		if (!new_lst)
			return (1);
		new_lst->nb = ft_atoi(str);
		lst->next = new_lst;
		new_lst->next = NULL;
	}
	return (0);
}
