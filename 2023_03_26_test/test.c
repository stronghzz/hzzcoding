#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>

int main()
{
    pid_t pid;
    int pip[2] = {-1};
    int pipe_id = pipe(pip);
    if(pipe_id < 0)
    {
        printf("no");
    }
    pid = fork();
    if(pid < 0)
    {
        printf("no fork");
        return -1;
    }
    else if(pid == 0)
    {
        char buf[1024] = {0};
        read(pip[0],buf,1023);
        printf("%s",buf);
    }
    else if (pid > 0)
    {
        char *ptr = "hello,world\n";
        write(pip[1],ptr,strlen(ptr));
    }
}