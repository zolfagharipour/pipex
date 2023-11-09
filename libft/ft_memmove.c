/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzolfagh <zolfagharipour@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 13:11:21 by mzolfagh          #+#    #+#             */
/*   Updated: 2023/09/05 13:11:23 by mzolfagh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	char	*ptr;
	size_t	i;

	if (!dest && !src)
		return (0);
	ptr = dest;
	if (dest < src)
	{
		ft_memcpy(ptr, src, n);
	}
	else
	{
		i = n -1;
		src += n;
		while (i <= n)
		{
			src--;
			ptr[i] = *(unsigned char *)src;
			i--;
		}
	}
	return (dest);
}
