#include "sshlib.h"

int main(int ac __attribute__((unused)), char **av)
{
	int i;
	int prompt_response;

	for (i = 1; av[i] != NULL; i++)
	{
		printf("%s\n", av[i]);
	}

	prompt_response = prompt();
	printf("Prompt Response: %d\n", prompt_response);
	return (0);
}

