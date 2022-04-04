#include "sshlib.h"

char **tokenizer2(char *line, char *sep)
{
    char *tokenize;
	char *vtokens[1024];
	char **vtptr = vtokens;
	int i = 0;
	
	
	while (vtokens[i])
	{
	    vtokens[i] = NULL;
		i++;
	}

    i = 0;
    tokenize = strtok(line, sep);
	if (tokenize == NULL)
	{
		printf("No separators found");
		exit(-1);
	}
	while (tokenize)
	{
	    vtokens[i] = tokenize;
		tokenize = strtok(NULL, sep);
		i++;
	}
	return (vtptr);
}
