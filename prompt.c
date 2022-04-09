#include "sshlib.h"

int prompt(void)
{
        size_t sizebuff = 64;
	char *buffer = NULL;
        char **path_tokens, **vtline;
        int response = 0;

	path_tokens = _tokenize(tokenizer(_getenv("PATH"), "="), ":");	
        while(response != -1)
        {
		printf("[hshc]>_ ");
		response = getline(&buffer, &sizebuff, stdin);
		buffer[_strlen(buffer) - 1] = '\0';
		vtline = tokenizer(buffer, " ");
		// Manage Exit // 
		__exit(vtline);
		_tokexe(vtline, path_tokens);	
		free(vtline);
		free(buffer);
		free(path_tokens);
	}
	return (response);
}
