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

int	child_proc(int *fd, char *av[], char *envp[])
{
	char	**cmds;
	char	*path;
	int		file;

	file = open(av[1], O_RDONLY);
	if (file == -1)
		return (0);
	dup2(fd[1], STDOUT_FILENO);
	dup2(file, STDIN_FILENO);
	close (fd[0]);
	close (fd[1]);
	close (file);
	cmds = cmd_seperate(av, FIRST_CMD);
	if (!cmds)
		return (0);
	path = path_finder(envp, cmds[0]);
	if (!path)
		return (free_split(cmds), 0);
	execve(path, cmds, envp);
	return (0);
}

int	parent_proc(int *fd, char *av[], char *envp[])
{
	char *path;
	char **cmds;
	int		file;

	file = open(av[4], O_WRONLY);
	if (file == -1)
		return (0);
	dup2(fd[0], STDIN_FILENO);
	dup2(file, STDOUT_FILENO);
	close (fd[0]);
	close (fd[1]);
	close (file);
	cmds = cmd_seperate(av, FIRST_CMD + 1);
	if (!cmds)
		return (0);
	path = path_finder(envp, cmds[0]);
	if (!path)
		return (free_split(cmds), 0);
	execve(path, cmds, envp);
	return (0);
}

int main(int ac, char *av[], char *envp[])
{
	char	*pathname;
	pid_t	pid;
	int		fd[2];
	int		x;

	if (pipe(fd) == -1)
		return (0);
	pid = fork();
	if (pid == 0)
	{
		child_proc(fd, av, envp);
	}
	parent_proc(fd, av, envp);

	close (fd[0]);
	close (fd[1]);
	waitpid(pid, NULL, 0);
}
