#include "sshlib.h"

char **ssh_tokenizer(char *line)
{
	int bufsize = 32, pos = 0;
	char **tokens = malloc(bufsize * sizeof(char*));
	char *token;

	if (!tokens)
	{
		fprintf(stderr, "ssh: allocation error\n");
		exit(-1);
	}

	token = strtok(line, " ");
	while (token != NULL)
	{
		tokens[pos] = token;
		pos++;

		if (pos >= bufsize)
		{
			bufsize += 32;
			tokens = realloc(tokens, bufsize * sizeof(char*));
			if (!tokens)
			{
				fprintf(stderr, "ssh: allocation error\n");
				exit(-1);
			}
		}
		token = strtok(NULL, " ");
	}
	tokens[pos] = NULL;
	return (tokens);
}
