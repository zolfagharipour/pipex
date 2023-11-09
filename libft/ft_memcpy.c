/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzolfagh <zolfagharipour@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 13:10:22 by mzolfagh          #+#    #+#             */
/*   Updated: 2023/09/05 13:10:24 by mzolfagh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned int		i;
	char				*ptr;

	i = 0;
	if (!src && !dest)
		return (0);
	ptr = dest;
	while (i < n)
	{
		ptr[i] = *(char *)src;
		src++;
		i++;
	}
	return (dest);
}
