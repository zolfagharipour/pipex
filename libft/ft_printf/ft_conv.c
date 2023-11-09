/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conv.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzolfagh <zolfagharipour@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/25 14:12:59 by mzolfagh          #+#    #+#             */
/*   Updated: 2023/09/25 14:13:03 by mzolfagh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_strupper(char *str)
{
	while (*str)
	{
		if (*str >= 'a' && *str <= 'z')
			*str -= 32;
		str++;
	}
	return (1);
}

char	*ft_conv_x(t_list1 *dlst)
{
	const char	*hex_digits = "0123456789abcdef";
	long int	nb;
	int			i;
	char		*str;

	nb = (unsigned)va_arg(*dlst->args, long int);
	i = ft_hexdigits(nb);
	str = (char *)malloc((i + 1) * sizeof(char));
	if (!str)
		return (0);
	str[i] = '\0';
	if (nb == 0)
		str[0] = '0';
	if (nb == 0)
		dlst->hash_flag = 0;
	while (nb > 0)
	{
		i--;
		str[i] = hex_digits[nb % 16];
		nb /= 16;
	}
	if (*dlst->str == 'X')
		dlst->hash_flag += ft_strupper(str);
	dlst->hash_flag += 2;
	return (str);
}

char	*ft_conv_p(t_list1 *dlst)
{
	const char			*hex_digits = "0123456789abcdef";
	unsigned long int	nb;
	int					i;
	char				*str;

	nb = (unsigned long int)va_arg(*dlst->args, void *);
	if (nb != 0)
		i = ft_hexdigits(nb) + 2;
	else
		i = 5;
	str = (char *)malloc((i + 1) * sizeof(char));
	if (!str)
		return (0);
	str[i] = '\0';
	str[0] = '0';
	str[1] = 'x';
	if (nb == 0)
		ft_strlcpy(str, "(nil)", 6);
	while (nb > 0)
	{
		i--;
		str[i] = hex_digits[nb % 16];
		nb /= 16;
	}
	return (str);
}

char	*ft_conv_c(t_list1 *dlst)
{
	char	*str;
	int		nbr;

	nbr = va_arg(*dlst->args, int);
	if (!nbr)
	{
		write (1, "\0", 1);
		dlst->printed++;
		if (dlst->width > 0)
			dlst->width--;
	}
	str = (char *)malloc(sizeof (char) * 2);
	if (!str)
		return (0);
	str[0] = nbr;
	str[1] = '\0';
	return (str);
}

char	*ft_conv_s(t_list1 *dlst)
{
	char	*str;
	char	*ptr;

	str = va_arg(*dlst->args, char *);
	if (!str)
	{
		ptr = (char *)malloc(sizeof(char) * 7);
		if (!ptr)
			return (0);
		ft_strlcpy(ptr, "(null)", 7);
	}
	else
	{
		ptr = (char *)malloc(sizeof(char) * (ft_strlen(str) + 1));
		if (!ptr)
			return (0);
		ft_strlcpy(ptr, str, ft_strlen(str) + 1);
	}
	return (ptr);
}
