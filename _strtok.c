#include "sshlib.h"
/**
 *_tokenize - tokenizer function
 *@line : command line
 *@sep : separator character
 *Return: tokenized
 */
char **_tokenize(char **line, const char *sep)
{
	char **tmp = NULL, **tokens = malloc(sizeof(char *));
	char *lline = NULL, *p = NULL;
	size_t n = 1;
	int success = 1, i = 0;

	for (i = 0; line[i] != NULL; i++)
	{
		lline = line[i];
	}
	p = strtok(lline, sep);
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
