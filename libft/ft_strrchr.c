/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzolfagh <zolfagharipour@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 13:26:29 by mzolfagh          #+#    #+#             */
/*   Updated: 2023/09/05 13:26:32 by mzolfagh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *str, int c)
{
	int	i;
	int	last;

	c = c % 128;
	i = 0;
	last = 0;
	while (str[i])
	{
		if (str[i] == c)
			last = i;
		i++;
	}
	if (c == str[i])
		last = i;
	if (last == 0 && str[0] != c)
		return (0);
	else
		return ((char *) str + last);
}
