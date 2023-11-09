/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_s.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzolfagh <zolfagharipour@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/25 13:55:52 by mzolfagh          #+#    #+#             */
/*   Updated: 2023/09/25 13:55:55 by mzolfagh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_nlen(int n)
{
	int		i;

	i = 0;
	if (n == 0)
		return (1);
	while (n != 0)
	{
		n /= 10;
		i++;
	}
	return (i);
}

char	*ft_itoa_s(int n, t_list1 *dlst)
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
		dlst->prefix = '-';
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

char	*ft_itoa_pf(long int n)
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
