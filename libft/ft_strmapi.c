/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzolfagh <zolfagharipour@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 13:23:59 by mzolfagh          #+#    #+#             */
/*   Updated: 2023/09/05 13:24:01 by mzolfagh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	size_t	len;
	int		i;
	char	*ptr;

	len = ft_strlen(s);
	i = len;
	ptr = (char *)malloc(sizeof(char) * (len + 1));
	if (!(ptr) || !s)
		return (0);
	ptr[len] = '\0';
	while (--i >= 0)
		ptr[i] = f(i, s[i]);
	return (ptr);
}
