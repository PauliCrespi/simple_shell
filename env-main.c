#include "sshlib.h"

int main(int ac __attribute__((unused)), char **av)
{
	int i;

	for (i = 1; av[i] != NULL; i++)
	{
		printf("%s\n", av[i]);
	}

	ssh_loop();
	return (0);
}

