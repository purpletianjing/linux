#include "exr6.h"

int main()
{
	pid_t pid = 0;
	int inc = 0;

	pid = fork();
	if(pid < 0)	{
		perror("fork");
		return -1;
	}
	else if(pid == 0)	{
	//	inc = nice(3);
		int prio = 0;
		printf("In child process!my pid is %d\n",getpid());
		prio = getpriority(PRIO_PROCESS,getpid());
		if(prio < 0)	{
			strerror(errno);
		}
		/*PRIO_PROCESS who为进程识别码
		*PRIO_PGRP who 为进程的组识别码
		*PRIO_USER who为用户识别码*/
		else	{
			printf("nice = %d\n",prio);
		}
		prio = setpriority(PRIO_PROCESS,getpid(),3);//设置优先级
		if(prio < 0)	{
			strerror(errno);
		}
		prio = getpriority(PRIO_PROCESS,getpid());
		printf("after set nice = %d\n",prio);
		printf("----------------------------\n");
		exit(0);
	}



	else	{
	wait(0);
		int prio = 0;
		prio = getpriority(PRIO_PROCESS,getpid());
		printf("parent process nice = %d\n",prio);
		prio = setpriority(PRIO_PROCESS,getpid(),9);
		if(prio < 0)	{
			strerror(errno);
		}
		printf("parent process is ending ……parent pid is %d\n",getpid());
		prio = getpriority(PRIO_PROCESS,getpid());
		printf("parent process nice = %d\n",prio);
	}
	
	return 0;
}
