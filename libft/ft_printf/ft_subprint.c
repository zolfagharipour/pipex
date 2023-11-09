/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_subprint.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzolfagh <zolfagharipour@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/25 14:01:01 by mzolfagh          #+#    #+#             */
/*   Updated: 2023/09/25 14:01:04 by mzolfagh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_hprefix(t_list1 *dlst)
{
	if (dlst->hash_flag == 6)
	{
		write(1, "0x", 2);
		dlst->printed += 2;
	}
	else if (dlst->hash_flag == 7)
	{
		write(1, "0X", 2);
		dlst->printed += 2;
	}
}

static void	ft_sprint(t_list1 *dlst)
{
	int	i;

	i = 0;
	if (dlst->hash_flag > 4 && !dlst->zero_flag)
		ft_hprefix(dlst);
	while (dlst->substr[i])
	{
		ft_putchar_fd(dlst->substr[i], 1);
		dlst->printed++;
		i++;
	}
	free(dlst->substr);
}

static void	ft_zeros(t_list1 *dlst)
{
	while (dlst->width > 0)
	{
		if (dlst->zero_flag)
		{
			write(1, "0", 1);
			dlst->printed++;
		}
		else
		{
			write(1, " ", 1);
			dlst->printed++;
		}
		dlst->width--;
	}
}

static void	ft_nomin(t_list1 *dlst)
{
	if (dlst->zero_flag && dlst->prefix)
	{
		ft_putchar_fd(dlst->prefix, 1);
		dlst->printed++;
	}
	ft_zeros(dlst);
	if (!dlst->zero_flag && dlst->prefix)
	{
		ft_putchar_fd(dlst->prefix, 1);
		dlst->printed++;
	}
	ft_sprint(dlst);
}

void	ft_subprint(t_list1 *dlst)
{
	if (dlst->hash_flag > 4 && dlst->zero_flag)
		ft_hprefix(dlst);
	else if (dlst->hash_flag > 4 && !dlst->zero_flag && dlst->width > 1)
		dlst->width -= 2;
	if (dlst->prefix && dlst->width > 1)
		dlst->width--;
	if (dlst->width > ft_strlen(dlst->substr))
		dlst->width -= ft_strlen(dlst->substr);
	else
		dlst->width = 0;
	if (!dlst->min_flag)
		ft_nomin(dlst);
	else
	{
		if (dlst->prefix)
		{
			ft_putchar_fd(dlst->prefix, 1);
			dlst->printed++;
		}
		ft_sprint(dlst);
		ft_zeros(dlst);
	}
}
