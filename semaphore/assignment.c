#include<stdio.h>
#include<pthread.h>
#include<stdlib.h>


pthread_cond_t cond1 = PTHREAD_COND_INITIALIZER; 
  

pthread_mutex_t lock1 = PTHREAD_MUTEX_INITIALIZER; 






pthread_cond_t cond2 = PTHREAD_COND_INITIALIZER; 
  
 
pthread_mutex_t lock2 = PTHREAD_MUTEX_INITIALIZER; 


int done=0;







void *communication(void *ptr)
{
char *message=(char*)ptr;

printf("%s",message);

done=1;//signal to information



 pthread_cond_signal(&cond1); // first signal


}








void *information(void *ptr)
{

char *message=(char*)ptr;

 pthread_cond_wait(&cond1, &lock1); //first wait

if(done==1)//condition
{


printf("%s",message);

}

done=2;//signal to technology

 pthread_cond_signal(&cond2);  //second signal
}








void *technology(void *ptr)
{
char *message=(char*)ptr;
 pthread_cond_wait(&cond2, &lock2); //second wait

if(done==2) //condition
{

done=0;
printf("%s",message);

}

}


void main()
{

pthread_t p1,p2,p3;
char *m1="communicaiton\n";
char *m2="information\n";
char *m3="technology\n";
pthread_create(&p1,NULL,communication,(void*)m1);


pthread_create(&p3,NULL,technology,(void*)m3);
pthread_create(&p2,NULL,information,(void*)m2);

pthread_join(p1,NULL);
pthread_join(p3,NULL);
pthread_join(p2,NULL);

}




