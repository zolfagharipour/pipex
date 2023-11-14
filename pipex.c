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

static int	child_proc(int *fd, char *av[], char *envp[], int arg)
{
	char	**cmds;
	char	*path;
	int		file;


	// dup2(fd[1], STDOUT_FILENO);
	// // dup2(file, STDIN_FILENO);
	// close (fd[0]);
	// close (fd[1]);
	// // close (file);
	dup2(fd[1], STDOUT_FILENO);
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

static int	parent_proc(int *fd, int ac, char *av[], char *envp[])
{
	char	*path;
	char	**cmds;
	int		file;

	file = open(av[ac - 1], O_WRONLY | O_CREAT | O_TRUNC, 0777);
	if (file == -1)
		return (perror(strerror(errno)), 0);
	dup2(fd[0], STDIN_FILENO);
	dup2(file, STDOUT_FILENO);
	close (fd[0]);
	close (fd[1]);
	close (file);
	cmds = cmd_seperate(av, ac - 4);
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
	char	*pathname;
	pid_t	pid;
	int		fd[2];
	int		file;
	int		i;

	file = open(av[1], O_RDONLY, 0777);
	if (file == -1)
		return (perror(strerror(errno)), 0);
	dup2(file, STDIN_FILENO);
	if (pipe(fd) == -1)
		return (0);
	// dup2(fd[1], STDOUT_FILENO);
	close (file);
	// close (fd[0]);
	// close (fd[1]);
	pid = fork();
	dup2(fd[0], STDIN_FILENO);

	if (pid == 0)
		child_proc(fd, av, envp, 0);
	if (waitpid(pid, NULL, 0) < 1)
		return (0);

	if (pipe(fd) == -1)
		return (0);
	// dup2(fd[1], STDOUT_FILENO);
	close (fd[0]);
	close (fd[1]);
	pid = fork();
	dup2(fd[0], STDIN_FILENO);
	if (pid == 0)
		child_proc(fd, av, envp, 1);
	if (waitpid(pid, NULL, 0) < 1)
		return (0);
	dup2(fd[0], STDIN_FILENO);
	
	if (pipe(fd) == -1)
		return (0);
	parent_proc(fd, ac, av, envp);
	close (fd[0]);
	close (fd[1]);
}
