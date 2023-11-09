/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzolfagh <zolfagharipour@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 13:25:54 by mzolfagh          #+#    #+#             */
/*   Updated: 2023/09/05 13:25:55 by mzolfagh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	l_len;

	i = 0;
	l_len = ft_strlen(little);
	if (ft_strlen(little) == 0)
		return ((char *)big);
	if (*big == 0 || len == 0)
		return (0);
	while (i < len - l_len + 1 && *big != '\0' && len != 0)
	{
		if (ft_strncmp(big, little, l_len) == 0 && ft_strlen(big) >= l_len)
			return ((char *)big);
		big++;
		i++;
	}
	return (0);
}
