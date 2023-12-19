/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omfelk <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 18:59:39 by omfelk            #+#    #+#             */
/*   Updated: 2023/12/04 23:33:55 by omfelk           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

bool	is_not_digit(char **str)
{
	int	i;
	int	j;

	i = 0;
	j = 1;
	while (str[j])
	{
		while (str[j][i])
		{
			if ((str[j][i] < '0' || str[j][i] > '9')
			&& str[j][i] != '-' && str[j][i] != ' ')
				return (ft_putstr("Error not everything is digital\n"), true);
			if (str[j][i] == '-' && str[j][i + 1] == '-')
				return (ft_putstr("Error the caract '-' is double\n"), true);
			if (str[j][i] == '-' && (str[j][i + 1] < '0'
				|| str[j][i + 1] > '9'))
				return (ft_putstr("Error not everything is digitall\n"), true);
			i++;
		}
		i = 0;
		j++;
	}
	return (false);
}

bool	is_double(t_list **lst)
{
	t_list	*tmp;
	t_list	*cpy_lst;
	int		nb;

	if (!*lst)
		return (true);
	cpy_lst = *lst;
	while ((cpy_lst)->next)
	{
		tmp = cpy_lst;
		nb = (cpy_lst)->nb;
		while ((cpy_lst)->next)
		{
			if ((cpy_lst)->next->nb == nb)
			{
				ft_putstr("error double\n");
				return (true);
			}
			(cpy_lst) = (cpy_lst)->next;
		}
		cpy_lst = tmp->next;
	}
	return (false);
}
