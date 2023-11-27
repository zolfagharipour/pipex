/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_here_doc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzolfagh <zolfagharipour@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 16:12:28 by mzolfagh          #+#    #+#             */
/*   Updated: 2023/11/27 16:12:30 by mzolfagh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	ft_here_doc(int ac, char *av[])
{
	int		fd;
	char	*gnl;

	fd = open(".here_doc", O_WRONLY | O_CREAT | O_TRUNC, 0777);
	if (fd == -1)
		exit(error_print(OPEN, "here_doc", av[0] + 2));
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
		exit(error_print(OPEN, "here_doc", av[0] + 2));
	dup2(fd, STDIN_FILENO);
	close (fd);
	unlink(".here_doc");
	fd = open(av[ac - 1], O_WRONLY | O_CREAT | O_APPEND, 0664);
	if (fd == -1)
		exit(error_print(OPEN, av[ac - 1], av[0] + 2));
	close (fd);
}
