#include "sshlib.h"
/**
 *inline_ssh - non interactive mode function
 *@ac : unused
 *@argv : command line
 *Return: Shell Status.
 */
int inline_ssh(int ac, char **argv)
{
	int flag = 0, i = 1, j = 0;
	char *path_cpy, *path = NULL;
	char **vtline = NULL;
	char **path_tok = NULL, **path_tokens = NULL, **ptrbuf = NULL;

	path = _getenv("PATH");
	path_cpy = malloc(_strlen(path) * sizeof(char));
	_strcpy(path_cpy, path);
	path_tok = tokenizer(path_cpy, "=");
	path_tokens = tokenizer(path_tok[1], ":");
	free(path_cpy);
	free(path_tok);
	vtline = malloc(ac * sizeof(char *));
	for (i = 1; argv[i] != NULL; i++, j++)
	{
		vtline[j] = malloc(_strlen(argv[i]) * sizeof(char));
		_strcpy(vtline[j], argv[i]);
	}
	if (manage_builtins(vtline[0]) == 0)
	{
		exit(0);
	}
	flag = is_combined_cmd(vtline);
	if (flag == -1)
		ptrbuf = look_cmd_in_path(vtline, path_tokens, 0);
	else
		printf("hsh: command not found.\n");
	if (ptrbuf != NULL)
	{
		_fork(ptrbuf);
	}
	else
	{
		printf("ssh: command not found.\n");
		exit(0);
	}
	free(vtline);
	free(path_tokens);
	return (0);
}
