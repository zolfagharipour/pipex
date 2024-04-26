/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzolfagh <zolfagharipour@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 16:13:19 by mzolfagh          #+#    #+#             */
/*   Updated: 2023/11/27 16:13:20 by mzolfagh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

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
		path = (envp, cmds[0]);
		if (!path)
		{
			free_split(cmds);
			return (EXIT_FAILURE);
		}
		execve(path, cmds, envp);
		free_split(cmds);
		exit (EXIT_FAILURE);
	}
	return (pid);
}

static void	file_open(char *av[], char **envp)
{
	int		file;
	int		fd[2];

	file = open(av[1], O_RDONLY);
	if (file == -1)
	{
		error_print(OPEN, av[1], av[0] + 2);
		file = open ("/dev/null", O_RDONLY);
		dup2 (file, STDIN_FILENO);
		close (file);
	}
	else
	{
		dup2 (file, STDIN_FILENO);
		close (file);
		if (pipe(fd) == -1)
			exit (EXIT_FAILURE);
		child_proc(fd, av, envp, 0);
		close (fd[1]);
		dup2(fd[0], STDIN_FILENO);
		close (fd[0]);
	}
}

static int	open_out(int ac, char **av)
{
	int	fd;

	if (!ft_strncmp(av[1], "here_doc", ft_strlen(av[1])))
		fd = open(av[ac - 1], O_WRONLY | O_CREAT | O_APPEND, 0664);
	else
		fd = open(av[ac - 1], O_WRONLY | O_CREAT | O_TRUNC, 0664);
	if (fd == -1)
		exit (error_print(OPEN, av[ac - 1], av[0] + 2));
	return (fd);
}

static int	proccess(int ac, char *av[], char *envp[])
{
	int	fd[2];
	int	i;
	int	pid;

	i = 1;
	if (pipe(fd) == -1)
		return (EXIT_FAILURE);
	while (i < ac - 4)
	{
		child_proc(fd, av, envp, i);
		close (fd[1]);
		(dup2(fd[0], STDIN_FILENO), close (fd[0]));
		if (pipe(fd) == -1)
			return (0);
		i++;
	}
	close (fd[1]);
	fd[1] = open_out(ac, av);
	pid = child_proc(fd, av, envp, i);
	if (waitpid(pid, NULL, 0) == -1)
		exit(EXIT_FAILURE);
	return (close (fd[0]), close (fd[1]), EXIT_SUCCESS);
}

int	main(int ac, char *av[], char *envp[])
{
	if (ac < 5)
		exit(error_print(ARG, "not enough", NULL));
	else if (ft_strncmp("here_doc", av[1], ft_strlen(av[1])) == 0)
	{
		if (ac < 6)
			exit(error_print(ARG, "not enough", NULL));
		ft_here_doc(ac, av);
	}
	else
		file_open(av, envp);
	if (proccess(ac, av, envp) == EXIT_FAILURE)
		exit(EXIT_FAILURE);
}
