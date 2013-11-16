#include <linux/syscalls.h>
#include <linux/types.h>
#include <linux/proc_fs.h>
#include <linux/init.h>
#include <linux/sched.h>
#include <asm/unistd.h>

asmlinkage long sys_set_hidden(pid_t pid, int hidden)
{
	long euid; 
	euid = sys_geteuid();
	struct task_struct *prcs;
	if(euid != 0)
		return EACCES;
	else
	{
		prcs = find_task_by_vpid(pid);
		prcs->hidden = hidden;
		return 0;
	}	
}


