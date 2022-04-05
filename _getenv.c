#include "sshlib.h"

char *_getenv(const char *name)
{
	extern char **environ;
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
