#ifndef SSHLIB_H
#define SSHLIB_H

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stddef.h>
#include <unistd.h>

int prompt(void);
//void ssh_strtok(char **arr, int size);
void tokenizer(char *line);

#endif
/* END OF FILE */

