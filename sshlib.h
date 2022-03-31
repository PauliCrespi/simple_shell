#ifndef SSHLIB_H
#define SSHLIB_H

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stddef.h>
#include <unistd.h>

void ssh_loop(void);
void ssh_strtok(char **arr, int size);
char **ssh_tokenizer(char *line);

#endif
/* END OF FILE */

