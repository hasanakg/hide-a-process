/*************************************************************************
 * Some test code to test system call 'set_hidden' does its job or not.  *
 * 															17.11.2013   *
 *************************************************************************/

#include <stdio.h>
#include <unistd.h>
#define NR_set_hidden 351

int main (void)
{
	 int choice;
	 pid_t pid;
	 printf("Enter (1) to fork current process or (2) to change a specific process' hidden flag. (0) to exit. ");
	 scanf("%d",&choice);

	 switch (choice)
	 {
		 case 0:
		 {
			printf("Good bye...\n");
			return 0;
		 }
		 break;
		 case 1: 
		 {
			pid = getpid();
			int frk = fork();
			if(frk == -1)
			{
				printf("Process couldn't fork succesfully. You have no permission to do this operation.\n");
				return -1;
			}	
			else if (frk == 0)
			{
				printf("I'm the child process and my pid is %d\n",getpid());
				return 0;
			}
			else
			{
				printf("I'm the parent process and my pid is %d\n",pid);
				return 0;
			}
		 }
		 break;
		 case 2:
		 {
			int flag;
			printf("Please enter pid of process you want to change its flag: "); 
			scanf("%d",&pid);
			printf("Please enter 'hidden' flag value: ");
			scanf("%d",&flag);
			long ret = syscall(NR_set_hidden, pid,flag);
			if (ret != 0)
			{
				printf("Hidden flag couldn't changed succesfully, error code is %ld.\n",ret);
				return -1;
			}
			else
			{
				printf("Hidden flag has been changed succesfully.\n");
				return 0;				
			}
		 }
		 break;
		 default:
			 return 0 ;
	 }

     
}