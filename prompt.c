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
	int response = 0, bints = 1;

	path_cpy = malloc((_strlen(_getenv("PATH")) + 1) * sizeof(char));
	_strcpy(path_cpy, _getenv("PATH"));
	path_tok = tokenizer(path_cpy, "=");
	path_tokens = _tokenize(path_tok, ":");
	free(path_cpy);
	while (response != -1)
	{
		printf("$ ");
		if (getline(&buffer, &sizebuff, stdin) == -1)
			break;
		if (buffer[0] == '\n' || buffer[0] == '\t')
			continue;
		buffer[_strlen(buffer) - 1] = '\0';
		vtline = tokenizer(buffer, " ");
		bints = manage_builtins(vtline[0]);
		if (bints == 0)
			continue;
		else if (bints == 6)
		{
			_free(4, buffer, vtline, path_tok, path_tokens);
			exit(0);
		}
		if (is_combined_cmd(vtline) == -1)
		{
			ptrbuf = look_cmd_in_path(vtline, path_tokens, 0);
			if (ptrbuf[0] == NULL)
				continue;
			_fork(ptrbuf);
		}
		else
			_fork(vtline);
	}
	_free(5, buffer, vtline, ptrbuf, path_tok, path_tokens);
	return (response);
}
