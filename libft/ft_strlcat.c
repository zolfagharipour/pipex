/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzolfagh <zolfagharipour@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 13:22:32 by mzolfagh          #+#    #+#             */
/*   Updated: 2023/09/05 13:22:34 by mzolfagh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t		len;

	len = ft_strlen(dst);
	if (len > size)
		return (size + ft_strlen(src));
	len += ft_strlen(src);
	while (*dst)
	{
		dst++;
		size--;
	}
	while (*src && size > 1)
	{
		*dst = *src;
		dst++;
		src++;
		size--;
	}
	*dst = '\0';
	return (len);
}
