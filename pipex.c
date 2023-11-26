#include "pipex.h"

static int	file_open(int ac, char *av[])
{
	int	file;

	file = open(av[1], O_RDONLY, 0777);
	if (file == -1)
		exit (error_print(OPEN, av[1]));
	dup2 (file, STDIN_FILENO);
	close (file);
	file = open(av[ac - 1], O_WRONLY | O_CREAT | O_TRUNC, 0777);
	if (file == -1)
		exit (error_print(OPEN, av[ac -1]));
	return (file);
}

static int	child_proc(int *fd, char *av[], char *envp[], int arg)
{
	char	**cmds;
	char	*path;

	dup2 (fd[1], STDOUT_FILENO);
	close (fd[0]);
	close (fd[1]);
	cmds = cmd_seperate(av, FIRST_CMD + arg);
	if (!cmds)
		return (0);
	path = path_finder(envp, cmds[0]);
	if (!path)
	{
		free_split(cmds);
		exit(EXIT_FAILURE);
	}
	execve(path, cmds, envp);
	free_split(cmds);
	exit(EXIT_FAILURE);
}

static int	proccess(int file, int ac, char *av[], char *envp[])
{
	pid_t	pid;
	int		fd[2];

	if (pipe(fd) == -1)
		return (EXIT_FAILURE);
	pid = fork();
	if (pid == 0)
	{
		close (file);
		if (!child_proc(fd, av, envp, 0))
			exit (EXIT_FAILURE);
	}
	close (fd[1]);
	dup2(fd[0], STDIN_FILENO);
	close (fd[0]);
	if (pipe(fd) == -1)
		return (EXIT_FAILURE);
	close (fd[1]);
	fd[1] = file;
	pid = fork();
	if (pid == 0)
		child_proc(fd, av, envp, 1);
	if (waitpid(pid, NULL, 0) == -1)
		exit(EXIT_FAILURE);
	(close (fd[0]), close (fd[1]));
}

int	main(int ac, char *av[], char *envp[])
{
	int		file;

	if (ac == 5)
	{
		file = file_open(ac, av);
		if (proccess(file, ac, av, envp) == EXIT_FAILURE)
			exit(EXIT_FAILURE);
	}
	else if (ac > 5)
	{
		error_print(ARG, "too many");
		exit (EXIT_FAILURE);
	}
	else
	{
		error_print(3, "not enough");
		exit (EXIT_FAILURE);
	}
}
