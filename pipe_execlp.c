#include <unistd.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>



int main(int ac, char *av[], char *envp[])
{
	int pid;
	char *str[] = {"/bin/bash", "-c", "ls", NULL};
	char *str1[] = {"/bin/bash", "-c", "grep p", NULL};
	int fd[2];

	pipe(fd);
	pid = fork();

	if (pid == 0)
	{
		dup2(fd[1], STDOUT_FILENO);
		close (fd[0]);
		close (fd[1]);
		execve("/bin/bash", str, envp);
	}
	
	int pid1 = fork();

	if (pid1 == 0)
	{
		dup2(fd[0], STDIN_FILENO);
		close (fd[0]);
		close (fd[1]);
		execve("/bin/bash", str1, envp);
	}
	close (fd[0]);
	close (fd[1]);
	waitpid(pid, NULL, 0);
	waitpid(pid1, NULL, 0);
	
}