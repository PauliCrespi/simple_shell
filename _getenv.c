#include "sshlib.h"
/**
 *_getenv - get enviroment variable function
 *@name : PATH
 *Return: PATH or NULL
 */
char *_getenv(const char *name)
{
	int i = 0;

	while (environ[i] != NULL)
	{
		if (_strncmp(name, environ[i], _strlen(name)) == 0)
		{
			return (environ[i]);
		}
		i++;
	}
	return (NULL);
}
/**
 *_getenv_all - func
 */
void _getenv_all(void)
{
	int i = 0;

	for (i = 0; environ[i] != NULL; i++)
	{
		printf("%s\n", environ[i]);
	}
}
