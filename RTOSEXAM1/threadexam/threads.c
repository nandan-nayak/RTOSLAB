

#include<stdio.h>
#include<pthread.h>
#include<stdlib.h>
#include<unistd.h>



pthread_cond_t cond1 = PTHREAD_COND_INITIALIZER; 
  

pthread_mutex_t lock1 = PTHREAD_MUTEX_INITIALIZER; 






pthread_cond_t cond2 = PTHREAD_COND_INITIALIZER; 
  
 
pthread_mutex_t lock2 = PTHREAD_MUTEX_INITIALIZER; 



int done=0;





void print(char *str1,char *str2)
{



printf("%s",str1);

sleep(2);
//if(done==0)
printf("%s",str2);
//done=1;


}




void *print_prathvi(void *str)
{
//printf("\npresent");

print("i am "," prathvi ");

//done=0;
pthread_cond_signal(&cond1);

}




void *print_raj(void *str)
{
//printf("\npresent");

//pthread_cond_signal(&cond1);


pthread_cond_wait(&cond1, &lock1);

print("i am "," raj ");

}


void main()
{

pthread_t p1,p2;


pthread_create(&p1,NULL,print_prathvi,NULL);


pthread_create(&p2,NULL,print_raj,NULL);



pthread_join(p1,NULL);
pthread_join(p2,NULL);

printf("\n");





}
