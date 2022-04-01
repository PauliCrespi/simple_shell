#include "sshlib.h"

void ssh_loop(void)
{
	size_t len = 0;
	ssize_t lineSize = 0;
	char **tokens;
	size_t i;

	do {
		char *line = NULL;
		printf("$ ");
		lineSize = getline(&line, &len, stdin);
		printf("Command: %s\n", line); 
		printf("Chars: %zu\n", lineSize -1);

		tokens = ssh_tokenizer(line);
		printf("Tokens: %zu\n", strlen(*tokens));
		free(line);
		for (i = 0; i < strlen(*tokens); i++)
			printf("Token: %s\n", tokens[i]);

	} while (lineSize != -1);

	return;
}
