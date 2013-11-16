#include <stdio.h>
#include <unistd.h>
#define NR_set_hidden 351

int main (void)
{
	 pid_t pid = getpid();
	 int y = syscall(NR_set_hidden, pid,0);
	 printf ("First Process ID: %d\n",pid);
	 
	 int testid = fork();
	 
	 if(testid == -1)
		printf("No permission to fork or another error on forking. \n");
	 else
		printf("Process id: %d\n",testid);
     
     return 0 ;
}
