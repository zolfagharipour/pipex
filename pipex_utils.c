/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzolfagh <zolfagharipour@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 16:13:55 by mzolfagh          #+#    #+#             */
/*   Updated: 2023/11/27 16:13:56 by mzolfagh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	**cmd_seperate(char *av[], int i)
{
	char	**cmds;

	cmds = ft_split(av[i + 2], ' ');
	if (!cmds)
		return (NULL);
	return (cmds);
}

int	error_print(int status, char *str, char *pipex)
{
	if (status == OPEN)
	{
		write(2, pipex, ft_strlen(pipex));
		write(2, ": ", 2);
		write(2, str, ft_strlen(str));
		write(2, ": ", 2);
		perror(NULL);
	}
	if (status == COMMAND)
	{
		write (2, str, ft_strlen(str));
		write (2, ": command not found\n", 20);
	}
	if (status == ARG)
	{
		write(2, "error: ", 7);
		write(2, str, ft_strlen(str));
		write(2, " arguments\n", 12);
	}
	return (EXIT_FAILURE);
}
