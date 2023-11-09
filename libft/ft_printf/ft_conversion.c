/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conversion.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzolfagh <zolfagharipour@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/25 13:50:00 by mzolfagh          #+#    #+#             */
/*   Updated: 2023/09/25 13:50:01 by mzolfagh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_hexdigits(unsigned long int dec)
{
	int		counter;

	counter = 0;
	while (dec > 0)
	{
		dec /= 16;
		counter++;
	}
	if (counter != 0)
		return (counter);
	else
		return (1);
}

static int	ft_prec_nb(t_list1 *dlst)
{
	char	*str;

	if (dlst->precision > ft_strlen(dlst->substr))
	{
		str = (char *)malloc(sizeof (char) * (dlst->precision + 1));
		if (!str)
			return (0);
		ft_memset(str, '0', dlst->precision - ft_strlen(dlst->substr));
		str[dlst->precision - ft_strlen(dlst->substr)] = '\0';
		ft_strlcat(str, dlst->substr, sizeof(char) * (dlst->precision + 1));
		free(dlst->substr);
		dlst->substr = str;
	}
	else if (dlst->precision == 0 && dlst->dot_flag && *dlst->substr == '0')
		dlst->substr[0] = '\0';
	return (1);
}

static int	ft_precision(t_list1 *dlst)
{
	char	*str;

	if (*dlst->str == 'd' || *dlst->str == 'i' || *dlst->str == 'x'
		|| *dlst->str == 'X' || *dlst->str == 'u')
	{
		if (!ft_prec_nb(dlst))
			return (0);
	}
	else if (*dlst->str == 's' && dlst->precision < ft_strlen(dlst->substr)
		&& dlst->dot_flag)
	{
		if (ft_strncmp(dlst->substr, "(null)", 7) == 0)
			dlst->precision = 0;
		str = (char *)malloc(sizeof (char) * (dlst->precision + 1));
		if (!str)
			return (0);
		ft_strlcpy(str, dlst->substr, sizeof (char) * (dlst->precision + 1));
		(free(dlst->substr), dlst->substr = str);
	}
	return (1);
}

int	ft_conversion(t_list1 *dlst)
{
	if (*dlst->str == 'c')
		dlst->substr = ft_conv_c(dlst);
	else if (*dlst->str == 's')
		dlst->substr = ft_conv_s(dlst);
	else if (*dlst->str == 'd' || *dlst->str == 'i')
		dlst->substr = ft_itoa_s(va_arg(*dlst->args, int), dlst);
	else if (*dlst->str == 'u')
		dlst->substr = ft_itoa_pf(va_arg(*dlst->args, unsigned int));
	else if (*dlst->str == 'x' || *dlst->str == 'X')
		dlst->substr = ft_conv_x(dlst);
	else if (*dlst->str == 'p')
		dlst->substr = ft_conv_p(dlst);
	else
		return (2);
	if (!dlst->substr)
		return (0);
	if (*dlst->str != 'd' && *dlst->str != 'i' && *dlst->str != 'p')
		dlst->prefix = '\0';
	if (*dlst->str != 'x' && *dlst->str != 'X')
		dlst->hash_flag = 0;
	if (*dlst->str == 'c' || *dlst->str == 's')
		dlst->zero_flag = 0;
	if (!ft_precision(dlst))
		return (0);
	return (1);
}
