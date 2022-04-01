#include <stdio.h>
#include <string.h>
#include <stdlib.h>
char* line()
{
	size_t sizebuff = 64;
	char *buffer;

	buffer = (char *)malloc(sizeof(char) * sizeof(char));
	if (buffer == NULL)
	{
		perror("Unable to allocate buffer");
		exit(1);
	}
	printf("$ ");
	getline(&buffer, &sizebuff, stdin);
	return(buffer);
}
int main()
{
	char *tokenize;
	char *argument	= line();

	tokenize = strtok(argument, " ");
	if (tokenize == NULL)
	{
		printf("%s", tokenize);
		printf("No separators found");
		return(1);
	}
	while (tokenize)
	{
		printf("%s\n", tokenize);
		tokenize = strtok(NULL, " ");
	}
	return (0);
}
