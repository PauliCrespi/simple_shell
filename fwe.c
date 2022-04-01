#include "sshlib.h"
int fwe(char *cmd, char *argv[])
{
	int pid, status, i = 0;

	for (i = 0; i <= 4; i++)
	{
		pid = fork();
		if (pid == 0)
		{
			execve(cmd, argv, NULL);
		}
		while(wait(&status) != pid);
	}
	return(pid);
}
