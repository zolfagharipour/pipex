/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzolfagh <zolfagharipour@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 16:13:29 by mzolfagh          #+#    #+#             */
/*   Updated: 2023/11/27 16:13:30 by mzolfagh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# define FIRST_CMD 0
# define OPEN 1
# define COMMAND 2
# define ARG 3

# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include <stdio.h>
# include <errno.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <fcntl.h>
# include "libft/libft.h"

char	*path_finder(char *envp[], char *cmd);
void	free_split(char **ptr);
void	ft_here_doc(int ac, char *av[]);
int		error_print(int status, char *str, char *pipex);
char	**cmd_seperate(char *av[], int i);

#endif
