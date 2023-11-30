/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omfelk <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 18:59:39 by omfelk            #+#    #+#             */
/*   Updated: 2023/11/30 11:45:41 by omfelk           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

bool	is_not_digit(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if ((str[i] < '0' || str[i] > '9') && str[i] != '-' && str[i] != ' ')
		{
			ft_putstr("not everything is digital\n");
			return (true);
		}
		if (str[i] == '-' && str[i + 1] == '-')
		{
			ft_putstr("the caract '-' is double\n");
			return (true);
		}
		if (str[i] == '-' && (str[i + 1] < '0' || str[i + 1] > '9'))
		{
			ft_putstr("not everything is digital\n");
			return (true);
		}
		i++;
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
