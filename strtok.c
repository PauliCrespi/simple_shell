<<<<<<< HEAD
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
char* line()
{
	size_t sizebuff = 64;
	char *buffer;
=======
#include "sshlib.h"
>>>>>>> 02e9323807f3c527360b5f71e84f1a8fc70fc616

void tokenizer(char *line)
{
	char *tokenize;

	tokenize = strtok(line, " ");
	if (tokenize == NULL)
	{
		printf("%s", tokenize);
<<<<<<< HEAD
		printf("No separators found");
		return(1);
=======
		puts("No separators found");
		exit(-1);
		//return (1);
>>>>>>> 02e9323807f3c527360b5f71e84f1a8fc70fc616
	}
	while (tokenize)
	{
		printf("%s\n", tokenize);
		tokenize = strtok(NULL, " ");
	}
	return;
}
