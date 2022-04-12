#include "sshlib.h"
/**
 *main - main function
 *@ac : number of arguments in command line
 *@av : arguments in command line
 *Return: 0 always
 */
int main(int ac, char **av)
{
	int hsh_resp = 1;

	if (ac == 1)
		hsh_resp = prompt();
	else
		hsh_resp = inline_ssh(ac, av);
	return (hsh_resp);
}
