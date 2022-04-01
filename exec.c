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
	int status, pd, i = 0;

	for(i = 0; i <= 4; i++)
	{
		pd = fork();
		if (pd == 0)
		{
			if (execve(argv[0], argv, NULL) == -1)
			{
				perror("Error:");
			}
			while (wait(&status) != pd)
			{
			}
		}
	}	
	return (0);
}
