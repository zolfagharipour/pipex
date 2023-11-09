/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzolfagh <zolfagharipour@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 13:15:37 by mzolfagh          #+#    #+#             */
/*   Updated: 2023/09/05 13:15:39 by mzolfagh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_word_counter(char const *str, char c)
{
	int	word_counter;
	int	word_begin;

	word_begin = 1;
	word_counter = 0;
	while (*str)
	{
		if (word_begin == 1 && *str != c)
		{
			word_counter++;
			word_begin = 0;
		}
		else if (*str == c)
			word_begin = 1;
		str++;
	}
	return (word_counter);
}

static char	**ft_free_malloc(char **ptr, int j)
{
	while (--j >= 0)
		free(ptr[j]);
	free (ptr);
	return (0);
}

static int	s_plus(const char *s, char c)
{
	int	i;

	i = 0;
	while (s[i] == c)
		i++;
	return (i);
}

char	**ft_split(char const *s, char c)
{
	int		i;
	int		j;
	char	**ptr;

	j = 0;
	ptr = (char **)malloc(sizeof(char *) * (ft_word_counter(s, c) + 1));
	if (!ptr)
		return (0);
	ptr[ft_word_counter(s, c)] = NULL;
	while (*s)
	{
		i = 0;
		s += s_plus(s, c);
		if (*s == '\0')
			return (ptr);
		while (s[i] != c && s[i])
			i++;
		ptr[j] = (char *)malloc(sizeof(char) * (i + 1));
		if (!(ptr[j]))
			return (ft_free_malloc(ptr, j));
		ft_strlcpy(ptr[j], s, i + 1);
		j++;
		s += i;
	}
	return (ptr);
}
