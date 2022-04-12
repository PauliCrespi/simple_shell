#include "sshlib.h"

/**
 *_strcpy - str copy
 *@dest : dest
 *@src : copied one
 *Return: void
 */
void _strcpy(char *dest, char *src)
{
	int i = 0;

	for (i = 0; src[i] != '\0'; i++)
	{
		dest[i] = src[i];
	}
	dest[i] = '\0';
}
