#include "sshlib.h"
/**
 *look_cmd_in_path - function
 *@vtline : command line
 *@path_tokens : tokenized path
 *@mode : int
 *Return: flag
 */
char **look_cmd_in_path(char **vtline, char **path_tokens, int mode)
{
	int i = 0, exe = -1, length = 0;
	char *strv = NULL, *find = NULL, **cmd_tokens = NULL;
	struct stat sfile;

	cmd_tokens = tokenizer(vtline[mode], "/");
	for (i = 0; cmd_tokens[i] != NULL; i++)
	{
		find = cmd_tokens[i];
	}
	for (i = 0; path_tokens[i] != NULL; i++)
	{
		length = ((_strlen(path_tokens[i]) + 1)  + _strlen(find) + 1);
		strv = malloc(length * sizeof(char));
		_strcpy(strv, path_tokens[i]);
		strcat(strv, "/");
		strcat(strv, find);
		exe = stat(strv, &sfile);
		if (exe == 0)
		{
			vtline[0] = malloc((_strlen(strv) + 1) * sizeof(char));
			_strcpy(vtline[0], strv);
			free(strv);
			break;
		}
	}
	free(cmd_tokens);
	return (vtline);
}
