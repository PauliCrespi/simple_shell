#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <string.h>
/**
 * main - execve example
 *
 * Return: Always 0.
 */
int main(void)
{
	char *argv[] = {"/bin/ls", "-l", "/tmp/", NULL};
	int status, pid, i = 0;

	for(i = 0; i <= 4; i++)
	{
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
			if (execve(argv[0], argv, NULL) == -1)
			{
				perror("Error:");
			}
		}
		else
		{
			wait(&status);
			printf("Oh, it's all better now\n");
		}
	}	
	return (0);
}
