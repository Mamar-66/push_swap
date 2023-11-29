/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omfelk <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 08:23:20 by omfelk            #+#    #+#             */
/*   Updated: 2023/11/29 10:35:17 by omfelk           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ft_bzero(void *s, size_t n)
{
	unsigned char	*tab;
	size_t			i;

	tab = (unsigned char *)s;
	i = 0;
	while (i < n)
	{
		tab[i] = 0;
		i++;
	}
	s = tab;
}
