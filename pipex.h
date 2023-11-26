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
int		ft_here_doc(int ac, char *av[], char *envp[]);
int		error_print(int status, char *str);
char	**cmd_seperate(char *av[], int i);

#endif