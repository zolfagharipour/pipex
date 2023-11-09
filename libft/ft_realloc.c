/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzolfagh <zolfagharipour@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 13:20:30 by mzolfagh          #+#    #+#             */
/*   Updated: 2023/09/05 13:20:32 by mzolfagh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_realloc(char *s, size_t size)
{
	size_t	i;
	size_t	len;
	char	*ptr;

	len = ft_strlen(s);
	ptr = (char *)malloc((size) * sizeof(char));
	if (!ptr)
		return (0);
	i = 0;
	while (i < len || i < size - 1)
	{
		ptr[i] = s[i];
		i++;
	}
	if (size > 0)
		ptr[i] = '\0';
	free (s);
	return (ptr);
}
