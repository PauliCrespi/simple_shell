#include "sshlib.h"
/**
 *__exit - exit function
 *@vtline : command line
 *Return: exit or not
 */
void __exit(char **vtline)
{
	int j = 0, i = 0;
	char *builtin_exit = "exit";

	if (_strlen(vtline[0]) == 4)
	{
		for (i = 0; i < 4; i++)
		{
			if (vtline[0][j] == builtin_exit[i])
			{
				j++;
			}
			else
			{
				break;
			}
		}
	}
	if (j == 4)
	{
		printf("Bye\n");
		exit(0);
	}
}
