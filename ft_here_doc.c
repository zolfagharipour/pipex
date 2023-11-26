#include "pipex.h"

int	ft_here_doc(int ac, char *av[], char *envp[])
{
	int		fd;
	char	*gnl;

	fd = open(".here_doc", O_WRONLY | O_CREAT | O_TRUNC, 0777);
	if (fd == -1)
		exit(error_print(OPEN, "here_doc"));
	gnl = get_next_line(STDIN_FILENO);
	while (gnl && ft_strncmp(av[2], gnl, ft_strlen(gnl) != 0))
	{
		write (fd, gnl, ft_strlen(gnl));
		free(gnl);
		gnl = get_next_line(STDIN_FILENO);
	}
	free(gnl);
	close (fd);
	fd = open(".here_doc", O_RDONLY);
	if (fd == -1)
		exit(error_print(OPEN, "here_doc"));
	dup2(fd, STDIN_FILENO);
	close (fd);
	unlink(".here_doc");
	fd = open(av[ac - 1], O_WRONLY | O_CREAT | O_APPEND, 0664);
	if (fd == -1)
		exit(error_print(OPEN, av[ac - 1]));
	return (fd);
}
