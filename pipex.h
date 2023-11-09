#ifndef PIPEX_H
# define PIPEX_H

# define FIRST_CMD 0

# include <unistd.h>
# include <stdlib.h>
# include <string.h>
#include <sys/types.h>
# include <sys/wait.h>
# include <fcntl.h>
# include "libft/libft.h"

char	*path_finder(char *envp[], char *cmd);
void	free_split(char **ptr);

#	include <stdio.h>

#endif