#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
/**
 * main - execve example
 *
 * Return: Always 0.
 */
int main(void)
{
<<<<<<< HEAD
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
=======
    char *argv[] = {"/bin/ls", "-l", "/usr/", NULL};

    printf("Before execve\n");
    if (execve(argv[0], argv, NULL) == -1)
    {
        perror("Error:");
    }
    printf("After execve\n");
    return (0);
>>>>>>> dfe7cd26f6bfcb0f68f14fea5199189cc15da5ef
}
