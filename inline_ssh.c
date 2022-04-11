#include "sshlib.h"
/**
 *inline_ssh - non interactive mode function
 *@ac : unused
 *@argv : command line
 *Return: Shell Status.
 */
int inline_ssh(int ac __attribute__((unused)), char **argv)
{
	int flag = 0;
	char *buf[1024], *path_cpy = NULL;
	char **path_tokens;

	path_cpy = malloc(_strlen(_getenv("PATH")) * sizeof(char));
	_strcpy(path_cpy, _getenv("PATH"));
	path_tokens = _tokenize(tokenizer(path_cpy, "="), ":");
	clean_buffer(buf);
	cpy_argv_to_buf(buf, argv, 1);
	if (manage_builtins(buf[0]) == 0)
	{
		exit(0);
	}
	flag = is_combined_cmd(buf);
	if (flag == -1)
		flag = look_cmd_in_path(argv, path_tokens, buf, 1);
	else
		printf("hsh: command not found.\n");
	if (flag == 0)
	{
		_fork(buf);

	}
	else
	{
		printf("ssh: command not found.\n");
		exit(0);
	}
	free(path_cpy);
	free(path_tokens);
	return (0);
}
