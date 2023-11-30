#include "../pipex.h"

int main(int ac, char **av, char **envp)
{
	int fd[2];
	char *str[] = {"cat", NULL};

	pipe (fd);
	close (fd[0]);
	fd[0] = open("/dev/null", O_RDONLY);
	dup2(fd[0], STDIN_FILENO);
	dup2(fd[1], STDOUT_FILENO);
	close (fd[1]);
	pid_t pid = fork();
	if (pid == 0)
	{
		// dup2(STDIN_FILENO, fd[0]);
		close (fd[0]);
		execve("/usr/bin/cat", str, envp);
	}
	dup2 (fd[0], STDIN_FILENO);
	close (fd[0]);
	pipe(fd);
	int file = open ("test", O_WRONLY | O_CREAT, 0777);
	dup2(file, STDOUT_FILENO);
	close (file);
	close (fd[0]);
	close (fd[1]);
	char *str1[] = {"cat", NULL};
	execve("/usr/bin/cat", str1, envp);
	
	
}