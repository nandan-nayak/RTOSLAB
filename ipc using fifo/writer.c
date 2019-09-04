#define _POSIX_SOURCE
#define _POSIX_C_SOURCE 200809L
#include<sys/types.h>
#include<unistd.h>
#include<fcntl.h>
#include<sys/stat.h>
#include<stdio.h>
int main()
{
int fd;
char buf[5]="HELLO";
if(mkfifo("fifo1",0777)==0)
printf("FIFO file created");
fd=open("fifo1",O_WRONLY,0);
write(fd,buf,5);
printf("run the reader process");
close(fd);
}
