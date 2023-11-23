#include "pipex.h"

static char	**cmd_seperate(char *av[], int i)
{
	char	**cmds;
	int		j;

	cmds = ft_split(av[i + 2], ' ');
	if (!cmds)
		return (NULL);
	return (cmds);
}

static int	child_proc(int *fd,char *av[], char *envp[], int arg)
{
	char	**cmds;
	char	*path;

	// dup2(fd[0], STDIN_FILENO);
	dup2(fd[1], STDOUT_FILENO);
	close (fd[0]);
	close (fd[1]);
	cmds = cmd_seperate(av, FIRST_CMD + arg);
	if (!cmds)
		return (0);
	path = path_finder(envp, cmds[0]);
	if (!path)
	{
		perror(strerror(errno));
		return (free_split(cmds), 0);
	}
	execve(path, cmds, envp);
	return (free_split(cmds), 0);
}


int	main(int ac, char *av[], char *envp[])
{
	pid_t	pid;
	int		fd[2];
	int		fd_tmp;
	int		file;
	int		i;

	i = 0;
	if (pipe(fd) == -1)
		return (0);
	file = open(av[1], O_RDONLY, 0777);
	dup2(file, STDIN_FILENO);
	while (i < ac - 4)
	{
		pid = fork();
		if (pid == 0)
			child_proc(fd, av, envp, i);
		close (fd[1]);
		dup2(fd[0], STDIN_FILENO);
		if (pipe(fd) == -1)
			return (0);		
		i++;
	}
	close (fd[1]);
	fd[1] = open(av[ac - 1], O_WRONLY | O_CREAT | O_TRUNC, 0777);
	if (fd[1] == -1)
		return (perror(strerror(errno)), 0);
	pid = fork();
	if (pid == 0)
		child_proc(fd, av, envp, i);
	close (fd[0]);
	close (fd[1]);
}
