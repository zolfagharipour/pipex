/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flags.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzolfagh <zolfagharipour@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/25 14:06:28 by mzolfagh          #+#    #+#             */
/*   Updated: 2023/09/25 14:06:30 by mzolfagh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_digitcount(int c)
{
	int	i;

	i = 0;
	while (c != 0)
	{
		c /= 10;
		i++;
	}
	return (i);
}

static void	f_detector(t_list1 *dlst)
{
	if (*dlst->str == '0' && !dlst->min_flag && !dlst->dot_flag)
		dlst->zero_flag = 1;
	else if (*dlst->str == '-')
	{
		dlst->min_flag = 1;
		dlst->zero_flag = 0;
	}
	else if (*dlst->str == '.')
	{
		dlst->dot_flag ++;
		dlst->zero_flag = 0;
	}
	else if (*dlst->str == '#')
		dlst->hash_flag += 4;
	else if (*dlst->str == ' ' && dlst->prefix != '+')
		dlst->prefix = ' ';
	else if (*dlst->str == '+')
		dlst->prefix = '+';
	else if (*dlst->str == '+')
		dlst->prefix = '+';
	else if (*dlst->str == '%')
		dlst->percent = 1;
}

int	ft_flags(t_list1 *dlst)
{
	while (!ft_isalpha(*dlst->str) && *dlst->str != '\0'
		&& *dlst->str != '%')
	{
		if (!ft_isalnum(*dlst->str) || *dlst->str == '0')
		{
			f_detector(dlst);
			dlst->str ++;
		}
		else
		{
			if (!dlst->dot_flag)
				dlst->width = ft_atoi(dlst->str);
			else
				dlst->precision = ft_atoi(dlst->str);
			if (!dlst->dot_flag)
				dlst->str += ft_digitcount(dlst->width);
			else
				dlst->str += ft_digitcount(dlst->precision);
		}
	}
	if (*dlst->str == '\0')
		return (0);
	else if (*dlst->str == '%')
		return (2);
	return (1);
}
