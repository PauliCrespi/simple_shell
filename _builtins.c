#include "sshlib.h"
/**
 * four_digits - Manage 4 digits builtin commands
 * @line: char ptr
 * Return: 0 on success or 1 on Fails
 */
int four_digits(char *line)
{
	char *builtin_exit = "exit", *builtin_help = "help";
	int i = 0, j = 0;

	for (i = 0; i < 4; i++)
	{
		if (line[j] == builtin_exit[i])
			j++;
		else
			break;
	}
	if (j == 4)
	{
		printf("Bye\n");
		exit(0);
	}
	j = 0;
	for (i = 0; i < 4; i++)
	{
		if (line[j] == builtin_help[i])
			j++;
		else
			break;
	}
	if (j == 4)
	{
		printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
		printf("~ Alex and Pauli's \"hsh\" for Holberton School Cohort 17\n");
		printf("~ Type program names and arguments, and hit enter.\n");
		printf("~ The following are built in:\n");
		printf("~\n~ exit - Exits program\n~ env  - Prints ENV\n~ help - FYI\n~\n");
		printf("~ Use the man command for information on other programs.\n");
		printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
		return (0);
	}
	return (1);
}

/**
 * three_digits - Manage 3 digits builtin commands
 * @line: char ptr
 * Return: 0 on success or 1 on Fails
 */
int three_digits(char *line)
{
	char *builtin_env = "env";
	int i = 0, j = 0;

	for (i = 0; i < 3; i++)
	{
		if (line[j] == builtin_env[i])
			j++;
		else
			break;
	}
	if (j == 3)
	{
		_getenv_all();
		return (0);
	}
	return (1);
}

/**
 * manage_builtins - Manage builtin commands
 * @line: char ptr
 * Return: 0 on success or 1 on Fails
 */
int manage_builtins(char *line)
{
	if (_strlen(line) == 3)
		return (three_digits(line));
	if (_strlen(line) == 4)
		return (four_digits(line));
	return (1);
}
