#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<sys/wait.h>
#include<string.h> 
void main()
{
int pid;
FILE *fp1=fopen("file.txt","w");
char a[50];
FILE *fp2;
pid=fork();

if(pid==0)
{
printf("\nchild process is writing into file ");
strcpy(a,"this is file content");
//fwrite(a,sizeof(a),1,fp1);
fprintf(fp1,"%s",a);
//printf("%s",a);
fclose(fp1);
printf("\nchild process execution completed");
}

else
{

wait(NULL);

printf("\n\n\n");


printf("\n parent process read the content of the file as \n");
fp2=fopen("file.txt","r");
fgets(a,255,fp2);
printf("\n%s",a);
fclose(fp2);
printf("\n parent process execution completed");

}

printf("\n\n");
}
