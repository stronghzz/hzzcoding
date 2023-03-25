#include <pthread.h>
#include <stdio.h>

void *mythread()
{
	for(int i = 0; i < 10; i++){
    printf("hello,mythread\n");   
	}
}

int main()
{
    pthread_t ntid;
    pthread_create(&ntid,NULL,mythread,NULL);
    pthread_join(ntid,NULL);
	printf("这是主进程\n");
    return 0;
}
