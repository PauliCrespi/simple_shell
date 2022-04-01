#include "sshlib.h"
int main(void)
{
	int pid, status, i = 0;
	char *argv[] = {"/tmp/ls", "-l", NULL};

	for (i = 0; i <= 4; i++)
	{
		pid = fork();
		if (pid == 0)
		{
			execve(argv[0], argv, NULL);
		}
		while(wait(&status) != pid);
	}
	return(pid);
}
