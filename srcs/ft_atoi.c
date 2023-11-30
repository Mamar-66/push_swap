/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omfelk <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 14:31:01 by omfelk            #+#    #+#             */
/*   Updated: 2023/11/30 11:52:46 by omfelk           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_atoi(const char *nptr)
{
	int	retour;
	int	i;
	int	signe;

	retour = 0;
	i = 0;
	signe = 1;
	while ((nptr[i] >= 9 && nptr[i] <= 13)
		|| (nptr[i] == 32 && nptr[i] != '\0'))
		i++;
	if (nptr[i] == '-' || (nptr[i] == '+' && nptr[i] != '\0'))
	{
		if (nptr[i] == '-')
			signe = signe * -1;
		i++;
	}
	while (nptr[i] >= '0' && nptr[i] <= '9' && nptr[i] != '\0')
	{
		retour = retour * 10 + (nptr[i] - '0');
		i++;
	}
	retour = retour * signe;
	return (retour);
}
