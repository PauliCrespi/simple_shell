#include "sshlib.h"

void tokenizer(char *line)
{
	char *tokenize;

	tokenize = strtok(line, " ");
	if (tokenize == NULL)
	{
		printf("%s", tokenize);
		puts("No separators found");
		exit(-1);
		//return (1);
	}
	while (tokenize)
	{
		printf("%s\n", tokenize);
		tokenize = strtok(NULL, " ");
	}
	return;
}
