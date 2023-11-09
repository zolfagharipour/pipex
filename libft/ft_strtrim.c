/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzolfagh <zolfagharipour@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/08 14:02:59 by mzolfagh          #+#    #+#             */
/*   Updated: 2023/09/08 14:03:02 by mzolfagh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	set_check(char c, char const *set)
{
	int	i;

	i = 0;
	while (set[i] != '\0')
	{
		if (c == set [i])
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	int		i;
	char	*s2;

	s1 = (char *)s1;
	while (*s1 != '\0' && set_check(*s1, set))
		s1++;
	i = ft_strlen(s1) -1;
	while (i > 0 && set_check(s1[i], set))
		i--;
	i++;
	s2 = (char *)malloc(sizeof(char) * i + 1);
	if (!s2)
		return (0);
	ft_memcpy(s2, s1, i);
	s2[i] = '\0';
	return (s2);
}
