/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzolfagh <zolfagharipour@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 13:29:24 by mzolfagh          #+#    #+#             */
/*   Updated: 2023/09/05 13:29:25 by mzolfagh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*ptr;

	if (ft_strlen(s) < start + len)
		len = ft_strlen(s) - start;
	if (start >= ft_strlen(s))
		len = 0;
	ptr = (char *)malloc(sizeof(char) * (len + 1));
	if (!ptr)
		return (0);
	if (start >= ft_strlen(s))
	{
		ptr[0] = '\0';
		return (ptr);
	}
	ptr[len] = '\0';
	while (len > 0)
	{
		len--;
		ptr[len] = s[start + len];
	}
	return (ptr);
}
