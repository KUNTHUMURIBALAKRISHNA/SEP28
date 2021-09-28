#include <stdio.h>
#include <pthread.h>// using for mutex also

int val=0;//global declaration
pthread_t tid[2];
unsigned int data = 0;

pthread_mutex_t mutex;
unsigned int lock_val;

void *even_num(void *p)
{
     lock_val = pthread_mutex_lock(&mutex);
     if(lock_val)
     {
	     printf("Lock is not acquired by mutex\n");
             pthread_exit(NULL);
     }
     do
     {
         if((data %2 == 0))
         {
             if(data!=0)
             printf("Even:%d\n",data);
             data++;
         }
         else
         {
             pthread_mutex_unlock(&mutex);
         }
     } while (data <= val);
}


void *odd_num(void * p1)
{
    lock_val = pthread_mutex_lock(&mutex);
	if(lock_val)
     {
	     printf("\n Lock not aquired");
         pthread_exit(NULL);
	 }

    do
    {
        if(data%2 != 0)
        {
            printf("Odd:%d\n",data);
            data++;
        }
        else
        {
            pthread_mutex_unlock(&mutex);
        }
    } while (data <= val);
}
void main(void)
{

    printf("Enter the value:\n");
    scanf("%d",&val);
    pthread_create(&tid[0],NULL,&even_num,NULL);
    pthread_create(&tid[1],NULL,&odd_num,NULL);

    pthread_join(tid[0],NULL);
    pthread_join(tid[1],NULL);
}



