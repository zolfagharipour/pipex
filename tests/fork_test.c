#include <stdio.h>
#include <unistd.h>

int main()
{
    int id1 = fork();
    int id2 = -1;
    if (id1 != 0)
        id2 = fork();
    printf("proccess ID: %d-%d\n", id1, id2);
}