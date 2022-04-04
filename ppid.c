#include "sshlib.h"

/**
 * myppid - PPID
 *
 * Return: PPID.
 */
int myppid(void)
{
	pid_t myppid;

	myppid = getppid();
	return (myppid);
}
