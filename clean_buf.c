#include "sshlib.h"
/**
 *clean_buffer - cleaner function
 *@buf : buffer
 */
void clean_buffer(char **buf)
{
	int i = 0;

	for (i = 0; i <= 1024; i++)
	{
		buf[i] = NULL;
	}
}
