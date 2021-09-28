#include <stdio.h>
#include <pthread.h>//thread
#include <unistd.h> // sleep

void *my_thread(void *p)
{    
     printf("Entered in pthread\n");
     printf("pthread ID: %lu\n",pthread_self());
     //sleep(5);
     for(int i=1;i<=100;i++)
     {
       printf("value:%d\n",i);
     }
     printf("Thread stop\n");
	//pthread_exit(NULL);
}
int main(void)
{
    pthread_t tid;
    int ret;
    ret = pthread_create(&tid,NULL,&my_thread,NULL);
    if (ret !=0) 
    {
            printf("return code from pthread_create() is %d\n", ret);
            return -1;
    }
    pthread_join(tid,NULL);
    printf("in Main function\n");
    printf("PID: %d\n", getpid());    
    return 0;
}
