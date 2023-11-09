/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzolfagh <zolfagharipour@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 13:14:07 by mzolfagh          #+#    #+#             */
/*   Updated: 2023/09/05 13:14:09 by mzolfagh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putendl_fd(char *s, int fd)
{
	size_t	len;
	size_t	i;

	i = 0;
	len = ft_strlen(s);
	while (i < len)
	{
		write (fd, &s[i], 1);
		i++;
	}
	write (fd, "\n", 1);
}
