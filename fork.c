#include "sshlib.h"
/**
 *_fork - fork, wait and execute function
 *@ptrbuf : buffer
 *Return: parent id
 */
void _fork(char **ptrbuf)
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
		if (execve(ptrbuf[0], ptrbuf, environ) == -1)
		{
			perror("hsh error");
		}
	}
	else
	{
		wait(&status);
	}
}
