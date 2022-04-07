#include "sshlib.h"

/**
 * main - 
 *
 * Return: Shell Status.
 */
int main(int ac, char **argv)
{
	int promptrespone = 1, i = 0, j = 1, exe = -1;
	char *buf[1024], *find;
	char **cmd_tokens, **ptrbuf, **ptrb;

	if (ac == 1)
		    prompt_response = prompt();
	else
	{
	// Copying Argv to Buffer // 
	for (j = 1; argv[j] != NULL; j++, i++)
	{
		buf[i] = argv[j];
	}
	ptrbuf = buf;
	// Getting the env and path to look in //
	ptrb = _envpath(ptrbuf);
	if (ptrb)
	{
		// FORK, EXECUTE AND WAIT //
		_fork(ptrb);
	}
	else
	{
		printf("ssh: command %s not found.\n", find);
		return (-1);
	}
	}
	return (0);
}
