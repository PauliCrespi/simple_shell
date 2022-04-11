#include "sshlib.h"
/**
 *_tokenize - tokenizer function
 *@line : command line
 *@sep : separator character
 *Return: tokenized
 */
char **_tokenize(char **line, const char *sep)
{
	char **tokens = NULL;
	char *lline = NULL, *p = NULL;
	size_t n = 1;
	int success = 1, i = 0;

	for (i = 0; line[i] != NULL; i++)
	{
		lline = line[i];
	}
	tokens = malloc(sizeof(char *) * lensep(lline, sep));
	p = strtok(lline, sep);
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
