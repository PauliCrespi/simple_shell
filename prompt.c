#include "sshlib.h"
/**
 *tokenpath - func
 *Return: pointer
 */
char **tokenpath(void)
{
	char *path, **path_tok = NULL, **path_tokens = NULL;
	char *path_cpy;

	path = _getenv("PATH");
	if (path != NULL)
	{
		path_cpy = malloc((_strlen(path) + 1) * sizeof(char));
		_strcpy(path_cpy, path);
		if (path_cpy != NULL)
			path_tok = tokenizer(path_cpy, "=");
		if (path_tok != NULL)
			path_tokens = _tokenize(path_tok, ":");
		free(path_cpy);
		free(path_tok);
	}
	return (path_tokens);
}

/**
 *prompt - interactive mode function
 *Return: 0 if success
 */
int prompt(void)
{
	size_t sizebuff = 64;
	char *buffer = NULL, **path_tokens = NULL, **ptrbuf = NULL, **vtline = NULL;
	int response = 0;

	path_tokens = tokenpath();
	while (response != -1 && path_tokens != NULL)
	{
		printf("[hshc]>_ ");
		response = getline(&buffer, &sizebuff, stdin);
		if (response == -1)
			break;
		buffer[_strlen(buffer) - 1] = '\0';
		vtline = tokenizer(buffer, " ");
		if (manage_builtins(vtline[0]) == 0)
			continue;
		else if (manage_builtins(vtline[0]) == 5)
		{
			free(buffer);
			free(vtline);
			free(path_tokens);
			exit(0);
		}
		is_combined_cmd(vtline);
		ptrbuf = look_cmd_in_path(vtline, path_tokens, 0);
		if (ptrbuf != NULL)
			_fork(ptrbuf);
		else
		{
			printf("hsh: command not found.\n");
			break;
		}
	}
		free(buffer);
		free(vtline);
		free(ptrbuf);
		free(path_tokens);
	return (response);
}
