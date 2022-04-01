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
	int pid, status, i = 0;

	for(i = 0; i <= 4; i++)
	{
		if ((pid = execve(argv[0], argv, NULL)) == -1)
		{
			perror("Error:");
		}
		while (wait(&status) != pid)
		{
		}
	}	
	return (0);
}
