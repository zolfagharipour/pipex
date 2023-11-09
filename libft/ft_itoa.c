/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzolfagh <zolfagharipour@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 12:56:21 by mzolfagh          #+#    #+#             */
/*   Updated: 2023/09/05 12:56:25 by mzolfagh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_nlen(int n)
{
	int		i;

	i = 0;
	if (n <= 0)
		i++;
	while (n != 0)
	{
		n /= 10;
		i++;
	}
	return (i);
}

char	*ft_itoa(int n)
{
	long int	ncpy;
	char		*nbr;
	int			i;

	ncpy = n;
	i = ft_nlen (ncpy);
	nbr = (char *)malloc(sizeof(char) * (i + 1));
	if (!nbr)
		return (0);
	nbr[i] = '\0';
	if (ncpy < 0)
	{
		nbr[0] = '-';
		ncpy *= -1;
	}
	if (ncpy == 0)
		nbr[0] = '0';
	while (ncpy > 0)
	{
		i--;
		nbr[i] = (ncpy % 10) + 48;
		ncpy /= 10;
	}
	return (nbr);
}
