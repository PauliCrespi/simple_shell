#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <string.h>
/**
 * main - fork, wait, execve
 *
 * Return: Always 0.
 */
int _fork(char **vtptr)
{
	int status, pid;

		pid = fork();
		if (pid == -1)
		{
			perror("Error: ");
			return (1);
		}
		if (pid == 0)
		{
			printf("Waiting for child proccess %d\n", pid);
			printf("PID: %d\n", getpid());
			printf("PPID: %d\n", getppid());
			sleep(3);
		}
		else
		{
			wait(&status);
			printf("Oh, it's all better now\n");
		}
		execve(vtptr[0], vtptr, NULL);	
	return (0);
}
