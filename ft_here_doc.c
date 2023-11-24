#include "pipex.h"

int	ft_here_doc(int *i, int ac, char *av[], char *envp[])
{
	int		fd;
	char	*gnl;

	fd = open("here_doc.txt", O_WRONLY | O_CREAT | O_TRUNC, 0777);
	if (fd == -1)
		return (perror(strerror(errno)), 0);
	gnl = get_next_line(STDIN_FILENO);
	while (gnl && ft_strncmp(av[2], gnl, ft_strlen(gnl) != 0))
	{
		write (fd, gnl, ft_strlen(gnl));
		free(gnl);
		gnl = get_next_line(STDIN_FILENO);
	}
	free(gnl);
	close (fd);
	fd = open("here_doc.txt", O_RDONLY, 0777);
	if (fd == -1)
		return (perror(strerror(errno)), 0);
	dup2(fd, STDIN_FILENO);
	close (fd);
	unlink("here_doc.txt");
	fd = open(av[ac - 1], O_WRONLY | O_CREAT | O_APPEND, 0777);
	if (fd == -1)
		return (perror(strerror(errno)), 0);
	return (fd);
}
