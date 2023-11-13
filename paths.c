#include "pipex.h"

void	free_split(char **ptr)
{
	int	j;

	j = 0;
	while (ptr[j])
	{
		free(ptr[j]);
		j++;
	}
	free (ptr);
}

static char	*path_access(char *path, char *cmd)
{
	char	**path_split;
	char	*tmp;
	int		j;

	path_split = ft_split(path, ':');
	if (!path_split)
		return (NULL);
	j = 0;
	while (path_split[j])
	{
		tmp = ft_strjoin(path_split[j], "/");
		if (!tmp)
			return (free_split(path_split), NULL);
		path = ft_strjoin(tmp, cmd);
		free(tmp);
		if (!path)
			return (free_split(path_split), NULL);
		if (!access(path, F_OK))
			return (free_split(path_split), path);
		free(path);
		j++;
	}
	free_split(path_split);
	return (NULL);
}

char	*path_finder(char *envp[], char *cmd)
{
	char	*path;
	int		i;

	i = 0;
	while (envp[i])
	{
		path = ft_strnstr(envp[i], "PATH", 4);
		if (path)
			return (path_access(path, cmd));
		i++;
	}
	return (NULL);
}
