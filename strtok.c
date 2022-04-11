#include "sshlib.h"
/**
 *tokenizer - tokenize function
 *@line : command line
 *@sep : separator character
 *Return: tokenized
 */
char **tokenizer(char *line, const char *sep)
{
	char **tmp = NULL, **tokens = malloc(sizeof(char *));
	size_t n = 1;
	int success = 0;
	char *p = NULL;

	p = strtok(line, sep);
	if (p != NULL)
		success = 1;
	else
		success = 0;
	while (success)
	{
		tmp = realloc(tokens, (n + 1) * sizeof(char *));
		if (tmp == NULL)
		{
			free(tokens);
			tokens = NULL;
			success = 0;
		}
		else
		{
			tokens = tmp;
			tokens[n - 1] = p;
			tokens[n] = NULL;
			++n;
			p = strtok(NULL, sep);
			if (p != NULL)
				success = 1;
			else
				success = 0;
		}
	}
	free(p);
	return (tokens);
}
