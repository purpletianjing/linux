#include "exr6.h"

int main()
{
	pid_t pid = 0;
	int inc = 0;

	pid = fork();
	if(pid < 0)
	{
		perror("fork");
		return -1;
	}
	else if(pid == 0)
	{
		inc = nice(3);
		if(inc < 0)
		{
			strerror(errno);
		}
		printf("In child process!my pid is %d\n",getpid());
		exit(0);
	}
	else
	{
	wait(0);
		inc = nice(19);
		if(inc < 0)
		{
			strerror(errno);
		}
		printf("parent process is ending ……\n");
	}
	
	return 0;
}
