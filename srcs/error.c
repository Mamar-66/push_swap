/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omfelk <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 18:59:39 by omfelk            #+#    #+#             */
/*   Updated: 2023/11/29 17:56:14 by omfelk           ###   ########.fr       */
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
		i++;
	}
	return (false);
}
