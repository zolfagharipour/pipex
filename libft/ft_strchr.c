/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzolfagh <zolfagharipour@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 13:18:22 by mzolfagh          #+#    #+#             */
/*   Updated: 2023/09/05 13:18:24 by mzolfagh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *str, int c)
{
	c = c % 128;
	while (*str)
	{
		if (*str == c)
			return ((char *) str);
		str++;
	}
	if (c == *str)
		return ((char *) str);
	else
		return (0);
}
