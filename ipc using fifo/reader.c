#define _POSIX_SOURCE
#define _POSIX_C_SOURCE 200809L
#include<sys/types.h>
#include<unistd.h>
#include<fcntl.h>
#include<sys/stat.h>
#include<stdio.h>
int main()
{
int fd,n;
char buf[5];
fd=open("fifo1",O_RDONLY,0);
while((n=read(fd,buf,sizeof(buf)))>0)
write(1,buf,n);
close(fd);
return 0;
}
