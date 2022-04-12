#include "sshlib.h"
/**
 *main - main function
 *@ac : number of arguments in command line
 *@av : arguments in command line
 *Return: 0 always
 */
int main(int ac, char **av)
{
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
