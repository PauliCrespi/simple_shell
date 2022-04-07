#include "sshlib.h"
/**
 *
 *
 *
 */
int seplen(char *line, const char *sep)
{
	int i = 0;
	int length = 0;

	for (i = 0; line[i] != '\0'; i++)
	{
		if (line[i] != sep[0])
		{
			length++;
		}
	}
	return (length);
}
