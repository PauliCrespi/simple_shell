#include "sshlib.h"

void ssh_loop(void)
{
	size_t len = 0;
	ssize_t lineSize = 0;

	do {
		char *line = NULL;
		printf("$ ");
		lineSize = getline(&line, &len, stdin);
		printf("Command: %s", line); 
		printf("Chars: %zu\n", lineSize -1);
		free(line);
	} while (lineSize != -1);
	return;
}
