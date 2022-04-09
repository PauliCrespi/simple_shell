#include "sshlib.h"

int main(int ac, char **av)
{
	int i;
	int interactive_ssh = 1;
	int noninteractive_ssh = 1;

	if (ac == 1)
	{
	    interactive_ssh = prompt();
	    printf("ssh response: %d\n", interactive_ssh);
	}
	else
	{
	    noninteractive_ssh = inline_ssh(ac, av);
	    printf("ssh response: %d\n", noninteractive_ssh);
	}	
	return (0);
}
