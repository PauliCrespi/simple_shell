#include "sshlib.h"

void ssh_loop(void)
{
	size_t len = 0;
	ssize_t lineSize = 0;
	char **tokens;

	do {
		char *line = NULL;
		printf("$ ");
		lineSize = getline(&line, &len, stdin);
		tokens = ssh_tokenizer(line);
		printf("Command: %s", line); 
		printf("Chars: %zu\n", lineSize -1);
		printf("Tokens: %zu\n", strlen(*tokens));
		free(line);
	} while (lineSize != -1);
	return;
}
