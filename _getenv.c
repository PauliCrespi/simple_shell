#include "sshlib.h"

char *_getenv(const char *name)
{
	extern char **environ;
	int i; 

	i = 0;
	while (environ[i] != NULL)                                                      
	{
	    if (strncmp(name, environ[i], strlen(name)) == 0) // Cambiar a _strlen y _strncmp
	    {
	        return (environ[i]);
	    }                                                 
		i++;                                                                    
	}
	
	return (NULL);
}
