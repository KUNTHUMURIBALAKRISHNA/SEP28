#include <stdio.h>
#include <unistd.h> //for sleep().
#include <pthread.h>
int val=10;
pthread_t tid[2];
//pthread_t tid1, tid2;
unsigned int data = 0;
void *even_num(void *ptr)
{
     do
     {
         if((data%2 == 0))
         {
             printf("Even:%d\n",data);
             data++;
         }
     } while (data <= val);
}
void* odd_num(void* ptr1)
{
    do
    {
        if(data%2 != 0)
        {
            printf("Odd:%d\n",data);
            data++;
        }
    } while (data <= val);
}
void main(void)
{
    pthread_create(&tid[0],NULL,&even_num,NULL);
    pthread_create(&tid[1],NULL,&odd_num,NULL);
    pthread_join(tid[0],NULL);
    pthread_join(tid[1],NULL);
}


