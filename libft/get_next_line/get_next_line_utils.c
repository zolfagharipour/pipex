/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzolfagh <zolfagharipour@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/05 16:15:58 by mzolfagh          #+#    #+#             */
/*   Updated: 2023/10/05 16:16:00 by mzolfagh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	new_line(t_gnl *buff)
{
	size_t	i;

	i = 0;
	if (!buff->buffer)
		return (0);
	while (i < buff->len && buff->buffer[i] != '\n')
		i++;
	return (i + 1);
}

size_t	ft_strlcpy_gnl(char *dst, const char *src, size_t size)
{
	size_t	i;

	i = 0;
	while (src && src[i] != '\0' && i < size - 1 && size != 0)
	{
		dst[i] = src[i];
		i++;
	}
	if (size != 0)
		dst[i] = '\0';
	i = 0;
	while (src && src[i] != '\0')
		i++;
	return (i);
}

char	*ft_free(t_gnl *buff)
{
	char	*str;

	str = (char *)malloc(sizeof(char) * buff->len + 1);
	if (!str)
	{
		free(buff->buffer);
		buff->buffer = NULL;
		return (NULL);
	}
	ft_strlcpy_gnl(str, buff->buffer, buff->len + 1);
	free(buff->buffer);
	buff->buffer = NULL;
	return (str);
}

char	*ft_merge(t_gnl *buff, char *s2, int *i)
{
	char	*str;

	s2[*i] = '\0';
	str = (char *)malloc(sizeof(char) * (buff->len + *i +1));
	if (!str)
	{
		*i = 0;
		return (buff->buffer);
	}
	ft_strlcpy_gnl(str, buff->buffer, buff->len + 1);
	ft_strlcpy_gnl(str + buff->len, s2, *i + 1);
	str[buff->len + *i] = '\0';
	free(buff->buffer);
	buff->buffer = NULL;
	buff->len += *i;
	return (str);
}
