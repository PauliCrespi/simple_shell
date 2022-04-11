#include "sshlib.h"
/**
 *prompt - interactive mode function
 *Return: 0 if success
 */
int prompt(void)
{
	size_t sizebuff = 64;
	char *buffer = NULL, **path_tok = NULL, **path_tokens = NULL;
	char **ptrbuf = NULL, **vtline = NULL, *path_cpy = NULL;
	int response = 0;

	path_cpy = malloc((_strlen(_getenv("PATH")) + 1) * sizeof(char));
	_strcpy(path_cpy, _getenv("PATH"));
	path_tok = tokenizer(path_cpy, "=");
	path_tokens = _tokenize(path_tok, ":");
	free(path_cpy);
	while (response != -1)
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
			free(path_tok);
			free(path_tokens);
			exit(0);
		}
		is_combined_cmd(vtline);
		ptrbuf = look_cmd_in_path(vtline, path_tokens, 0);
		_fork(ptrbuf);
	}
		free(buffer);
		free(vtline);
		free(ptrbuf);
		free(path_tok);
		free(path_tokens);
	return (response);
}
