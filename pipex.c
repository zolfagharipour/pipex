/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzolfagh <zolfagharipour@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 16:13:42 by mzolfagh          #+#    #+#             */
/*   Updated: 2023/11/27 16:13:44 by mzolfagh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

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

static void	first_proc(char *av[], char **envp)
{
	int		file;
	int		fd[2];
	pid_t	pid;

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
		pid = fork();
		if (pid == 0)
			child_proc(fd, av, envp, 0);
		close (fd[1]);
		dup2(fd[0], STDIN_FILENO);
		close (fd[0]);
	}
}

static int	second_proc(int ac, char *av[], char *envp[])
{
	pid_t	pid;
	int		fd[2];

	if (pipe(fd) == -1)
		return (EXIT_FAILURE);
	close (fd[1]);
	fd[1] = open(av[ac - 1], O_WRONLY | O_CREAT | O_TRUNC, 0664);
	if (fd[1] == -1)
		exit (error_print(OPEN, av[ac -1], av[0] + 2));
	pid = fork();
	if (pid == 0)
		child_proc(fd, av, envp, 1);
	if (waitpid(pid, NULL, 0) == -1)
		exit(EXIT_FAILURE);
	return (close (fd[0]), close (fd[1]), EXIT_SUCCESS);
}

int	main(int ac, char *av[], char *envp[])
{
	if (ac == 5)
	{
		first_proc(av, envp);
		if (second_proc(ac, av, envp) == EXIT_FAILURE)
			exit(EXIT_FAILURE);
	}
	else if (ac > 5)
	{
		error_print(ARG, "too many", NULL);
		exit (EXIT_FAILURE);
	}
	else
	{
		error_print(ARG, "not enough", NULL);
		exit (EXIT_FAILURE);
	}
}
