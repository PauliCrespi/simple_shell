#include "sshlib.h"
/**
 *
 *
 *
 */
pid_t  _fork(char **ptrbuf)
{
	int status;
	pid_t pid = -1;

	pid = fork();
	if (pid == -1)
	{
		perror("Error: ");
		return (-1);
	}
	if (pid == 0)
	{
		sleep(1);
		if (execve(ptrbuf[0], ptrbuf, NULL) == -1)
		{
			perror("Error");
			return (-1);
		}
	}
	else
	{
		wait(&status);
		printf("Status: %d\n", status);
	}
	return (pid);
}
