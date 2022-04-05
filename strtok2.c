#include "sshlib.h"
char **tokenizer2(char *line, char *sep)
{
	char *tokenize;
	char *vtokens;
	char **vtptr = vtokens;
	int i = 0;

	vtokens = malloc(_strlen(line) * sizeof(char));
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
	free(vtokens);
	return (vtptr);
}
