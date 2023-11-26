#include "../pipex.h"

int main(int ac, char *av[], char *envp[])
{
	char *str = "/usr/bin/cat";
	if (!access(str, F_OK | X_OK))
		printf("YESS!!\n");
	else
		printf("OPS!\n");

}