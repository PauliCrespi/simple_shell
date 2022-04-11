#include "sshlib.h"
/**
 * _strncmp - string compare up to n char
 *@s1 : s
 *@s2 : s2
 *@n : int n
 *Return: counter
 */
int _strncmp(const char *s1, char *s2, int n)
{
	int i = 0;

	while (i < n && s1[i] != '\0' && s2[i] != '\0')
	{
		if (s1[i] == s2[i])
		{
			i++;
		}
		else
		{
			return (-1);
		}
	}
	return (0);
}
