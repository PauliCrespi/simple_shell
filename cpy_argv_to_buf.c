#include "sshlib.h"
/**
 *cpy_argv_to_buf - copy arguments into a buffer function
 *@buf : buffer
 *@vtline : command line
 *@mode : int
 */
void cpy_argv_to_buf(char **buf, char **vtline, int mode)
{
	int j = 1, i = 0;

	if (mode == 0)
	{
		i = 0;
		while (vtline[i] != NULL)
		{
			buf[i] = malloc(_strlen(vtline[i]) * sizeof(char));
			_strcpy(buf[i], vtline[i]);
			i++;
		}
	}
	else if (mode == 1)
	{
		i = 0;
		j = 1;
		while (vtline[j] != NULL)
		{
			buf[i] = malloc(_strlen(vtline[j]) * sizeof(char));
			_strcpy(buf[i], vtline[j]);
			i++;
			j++;
		}
	}
}
