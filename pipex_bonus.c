#include "pipex.h"

static int	file_open(int ac, char *av[])
{
	int	file;

	file = open(av[1], O_RDONLY, 0777);
	if (file == -1)
		exit (error_print(OPEN, av[1]));
	dup2(file, STDIN_FILENO);
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
	pid_t	pid;

	pid = fork();
	if (pid == 0)
	{
		dup2(fd[1], STDOUT_FILENO);
		close (fd[0]);
		close (fd[1]);
		cmds = cmd_seperate(av, FIRST_CMD + arg);
		if (!cmds)
			exit (EXIT_FAILURE);
		path = path_finder(envp, cmds[0]);
		if (!path)
		{
			free_split(cmds);
			exit (EXIT_FAILURE);
		}
		execve(path, cmds, envp);
		free_split(cmds);
		exit (EXIT_FAILURE);
	}
	return (pid);
}

static int	proccess(int file, int ac, char *av[], char *envp[])
{
	int	fd[2];
	int	i;
	int	pid;

	i = 0;
	if (ft_strncmp("here_doc", av[1], ft_strlen(av[1])) == 0)
		i = 1;
	if (pipe(fd) == -1)
		return (EXIT_FAILURE);
	while (i < ac - 4)
	{
		if (child_proc(fd, av, envp, i) == EXIT_FAILURE)
			exit (EXIT_FAILURE);
		close (fd[1]);
		(dup2(fd[0], STDIN_FILENO), close (fd[0]));
		if (pipe(fd) == -1)
			return (0);
		i++;
	}
	close (fd[1]);
	fd[1] = file;
	pid = child_proc(fd, av, envp, i);
	if (waitpid(pid, NULL, 0) == -1)
		exit(EXIT_FAILURE);
	(close (fd[0]), close (fd[1]));
}

int	main(int ac, char *av[], char *envp[])
{
	int		fd[2];
	int		file;

	if (ac < 5)
		exit(error_print(ARG, "not enough"));
	else if (ft_strncmp("here_doc", av[1], ft_strlen(av[1])) == 0)
	{
		if (ac < 6)
			exit(error_print(ARG, "not enough"));
		file = ft_here_doc(ac, av, envp);
	}
	else
		file = file_open(ac, av);
	if (proccess(file, ac, av, envp) == EXIT_FAILURE)
		exit(EXIT_FAILURE);
}
