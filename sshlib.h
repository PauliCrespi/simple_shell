#ifndef SSHLIB_H
#define SSHLIB_H
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stddef.h>
#include <unistd.h>

int prompt(void);
char **tokenizer(char *line);
char **tokenizer2(char *line, char *sep);
int mypid(void);
int myppid(void);
char *_getenv(const char *name);
int _strlen(const char *s);
int _strncmp(const char *s1, char *s2, int n);

#endif
/* END OF FILE */

