#include "sshlib.h"

int main(int ac, char **av)
{
	int i;
	int prompt_response = 1;

	for (i = 1; av[i] != NULL; i++)
	{
		printf("%s\n", av[i]);
	}
    if (ac == 1)
	    prompt_response = prompt();
    return (0);
}

