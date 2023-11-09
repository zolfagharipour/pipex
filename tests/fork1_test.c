#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

int main()
{
    pid_t pid = fork();
    
	if(pid < 0)
		printf("Fork failed!");
    else if (pid == 0)
        printf("Child process ID: %d\n", pid);
	else
	{
		waitpid(0, NULL, 0);
		printf("Parent process ID: %d\n", pid);
	}
}