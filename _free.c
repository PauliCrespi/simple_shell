#include "sshlib.h"
/**
 * _free - variadic free
 * Return: void
 * @ac: int
 */
void _free(int ac, ...)
{
	va_list ap;
	int i;

	va_start(ap, ac);
	for (i = 0; i < ac; i++)
		free(va_arg(ap, void*));
	va_end(ap);
}
