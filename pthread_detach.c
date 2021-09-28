#include <stdio.h>
#include <pthread.h>//thread
#include <unistd.h>//sleep
#include <stdlib.h>

void *thread(void *arg)
{
 	pthread_detach(pthread_self());
	sleep(5);
 	printf("In Thread\n");
	for(int i=1;i<=100;i++)
        {
		printf("Val:%d\n",i);
         }
 	//pthread_exit(NULL);
}
int main(int argc, char *argv[])
{
 	pthread_t tid;
 	int ret = pthread_create(&tid, NULL, thread, NULL);	
 	if (ret!=0) 
        {
 	 	printf("unable to create thread\n");
 	 	exit(1);
 	}
 	printf("Thread created in Main\n");
	printf("In main...");
	//pthread_join(tid,NULL);
 	pthread_exit(NULL);
	printf("After exit main");
	return 0;
}

