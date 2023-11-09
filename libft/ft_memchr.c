/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzolfagh <zolfagharipour@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 13:07:23 by mzolfagh          #+#    #+#             */
/*   Updated: 2023/09/05 13:07:24 by mzolfagh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned int		i;
	char				*ptr;

	i = 0;
	ptr = (void *)s;
	while (i < n)
	{
		if ((unsigned char) c == *(unsigned char *)s)
			return (ptr + i);
		s++;
		i++;
	}
	return (NULL);
}
