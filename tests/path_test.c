#include <unistd.h>
#include <stdio.h>
#include <strings.h>


int main(int ac, char *av[], char *envp[])
{
    int i = 0;

    while (envp[i] != NULL)
    {
        printf("%s\n\n", envp[i]);
        i++;
    }
}