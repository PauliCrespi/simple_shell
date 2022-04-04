#include "sshlib.h"

/**
 * mypid - PID
 *
 * Return: PID.
 */
int mypid(void)
{
	pid_t mypid;

	mypid = getpid();
	return (mypid);
}
