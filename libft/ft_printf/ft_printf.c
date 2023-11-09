/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzolfagh <zolfagharipour@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/25 13:45:43 by mzolfagh          #+#    #+#             */
/*   Updated: 2023/09/25 13:45:47 by mzolfagh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_init(t_list1 *dlst)
{
	dlst->substr = 0;
	dlst->prefix = 0;
	dlst->dot_flag = 0;
	dlst->min_flag = 0;
	dlst->zero_flag = 0;
	dlst->hash_flag = 0;
	dlst->percent = 0;
	dlst->width = 0;
	dlst->precision = 0;
}

static void	ft_printcent(t_list1 *dlst)
{
	write (1, "%%", 1);
	dlst->printed++;
	dlst->str += 1;
}

static int	ft_percent(t_list1 *dlst)
{
	const char	*ptr;
	int			p;

	ptr = dlst->str;
	if (!ft_flags(dlst))
		return (0);
	else if (*dlst->str == '%')
		ft_printcent(dlst);
	else
	{
		p = ft_conversion(dlst);
		if (p == 2)
		{
			dlst->str = ptr;
			(write(1, "%%", 1), dlst->printed++);
		}
		else if (p == 0)
			return (0);
		else
		{
			dlst->str++;
			ft_subprint(dlst);
		}
	}
	return (1);
}

static int	ft_blockprint(t_list1 *dlst)
{
	while (*dlst->str != '\0')
	{
		ft_init(dlst);
		if (*dlst->str == '%')
		{
			dlst->str++;
			if (*dlst->str != '%')
			{
				if (!ft_percent(dlst))
					return (0);
			}
			else
				ft_printcent(dlst);
		}
		else
		{
			ft_putchar_fd(*dlst->str, 1);
			dlst->printed++;
			dlst->str++;
		}
	}
	return (1);
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	t_list1	dlst;

	va_start(args, format);
	ft_init(&dlst);
	if (format == 0)
		return (-1);
	dlst.printed = 0;
	dlst.str = format;
	dlst.args = &args;
	if (!ft_blockprint(&dlst))
	{
		va_end(args);
		return (-1);
	}
	va_end(args);
	return (dlst.printed);
}
