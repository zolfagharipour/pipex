#include "../pipex.h"

int	main()
{
	perror("testing");
	int i = 0;
	while (i < 150)
	{
		errno = i;
		printf("%d: %s\n", i, strerror(errno));
		i++;
	}
}