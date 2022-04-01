#include "sshlib.h"

char **tokenizer(char *line)
{
	char *tokenize;
	char *vtokens[1024];
	char **vtptr = vtokens;
	int i = 0;

    tokenize = strtok(line, " ");
	if (tokenize == NULL)
	{
		printf("%s", tokenize);
		printf("No separators found");
		exit(-1);
		//return (1);
	}
	while (tokenize)
	{
	    //printf("Token: %s\n", vtokens[i]);
		//printf("%s\n", tokenize);
		
	    vtokens[i] = tokenize;
		tokenize = strtok(NULL, " ");
		i++;
	}
	
	return (vtptr);
}
