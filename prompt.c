#include "sshlib.h"
/**
 *prompt - interactive mode function
 *Return: 0 if success
 */
int prompt(void)
{
	size_t sizebuff = 64;
	char *buf[1024] = { NULL };
	char *buffer = NULL, *path = NULL, **path_tokens = NULL, **vtline = NULL, *path_cpy;
	int response = 0, flag = 0;

	path =  _getenv("PATH");
	if (path != NULL)
	{
		path_cpy = malloc((_strlen(path) + 1) * sizeof(char));
		_strcpy(path_cpy, path);
		path_tokens = _tokenize(tokenizer(path_cpy, "="), ":");
		free(path_cpy);
	}
	while (response != -1)
	{
		printf("[hshc]>_ ");
		response = getline(&buffer, &sizebuff, stdin);
		buffer[_strlen(buffer) - 1] = '\0';
		vtline = tokenizer(buffer, " ");
		clean_buffer(buf);
		if (manage_builtins(vtline[0]) == 0)
		{
			continue;
		}
		cpy_argv_to_buf(buf, vtline, 0);
		flag = is_combined_cmd(vtline);
		if (flag == -1)
			flag = look_cmd_in_path(vtline, path_tokens, buf, 0);
		else
			printf("hsh: command not found.\n");
		if (flag == -1)
		{
			printf("hsh: command not found.\n");
			continue;
		}
		if (flag == 0)
			_fork(buf);
		else
			printf("hsh: command not found.\n");
		free(vtline);
	}
		free(path_tokens);
	return (response);
}
