#ifndef SSHLIB_H
#define SSHLIB_H
#include <sys/types.h>
#include <sys/wait.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stddef.h>
#include <unistd.h>

int prompt(void);
//void ssh_strtok(char **arr, int size);
char **tokenizer(char *line);

#endif
/* END OF FILE */

