#include "sshlib.h"
/**
 *
 *
 *
 */
int lensep(char *line,  const char *sep)
{
	int i = 0;

	for (i = 0; line[i] != '\0'; i++)
	{
		if (line == sep)
			i--;
	}
	return (i);
}
/**
 *tokenizer - tokenize function
 *@line : command line
 *@sep : separator character
 *Return: tokenized
 */
char **tokenizer(char *line, const char *sep)
{
	char **tokens = malloc(sizeof(char *) * lensep(line, sep));
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
		if (tokens != NULL)
		{
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
