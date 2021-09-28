#include <stdio.h>
#include <pthread.h>//thread

int val=10;
pthread_t tid;

void *add_num(void *p)
{    
     int *data_ptr = (int*) ptr;//type conversion 
     int data = *data_ptr;
     printf("Entered value:%d\n",val);
     printf("data:%d\n",data);//prints user data
     printf("Addition is:%d\n",(val+data)); //addition of user data and value
     printf("pthread Id:%lu\n",pthread_self());//prints thread id
}
int main(void)
{
    int data, ret=0;
    printf("Enter a number\n");
    scanf("%d",&data);
    ret = pthread_create(&tid,0,&add_num,&data);
    if (ret) 
    {
            printf("return code from pthread_create() is %d\n", ret);
            return -1;
    }
    pthread_join(tid,NULL);
    return 0;
}
