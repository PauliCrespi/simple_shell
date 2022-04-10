#include "sshlib.h"
/**
 *_fork - fork, wait and execute function
 *@ptrbuf : buffer
 *Return: parent id
 */
pid_t  _fork(char **ptrbuf)
{
	int status = 0;
	pid_t pid = -1;

	pid = fork();
	if (pid == -1)
	{
		perror("hsh error");
	}
	if (pid == 0)
	{
		if (execve(ptrbuf[0], ptrbuf, NULL) == -1)
		{
			perror("hsh error");
		}
	}
	else
	{
		wait(&status);
		printf("hsh status: %d\n", status);
	}
	return (pid);
}
