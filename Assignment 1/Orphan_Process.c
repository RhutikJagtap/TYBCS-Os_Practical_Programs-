/*Set B- Q.2) Write a C program to illustrate the concept of orphan process. 
Parent process creates a child and terminates before child has finished its task.
So child process becomes orphan process. (Use fork(), sleep(), getpid(), getppid()).*/
#include <stdio.h> 
#include <sys/types.h>
#include <unistd.h>
int main()
{ 
 int pid;
 pid=getpid(); 
 printf("Current Process ID is : %d\n",pid); 
 printf("\n[Forking Child Process ... ] \n"); 
 pid=fork(); 
 if(pid < 0) 
 {    
  printf("\nProcess can not be created ");
 } 
 else
 {
         if(pid==0)
  { 
   printf("\nChild Process is Sleeping ..."); 
   sleep(5); 
   printf("\nOrphan Child's Parent ID : %d",getppid()); 
  }
 
  else
  { /* Parent Process */
   printf("\nParent Process Completed ..."); 
  } 
 }
 return 0; 
}
// @Code By Rj
