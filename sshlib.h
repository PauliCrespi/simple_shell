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
int main(int ac, char **av);
int prompt(void);
char **tokenizer(char *line);
pid_t _fork(char **ptrbuf);
char **tokenizer2(char *line, char *sep);
char **_envpath(char **ptrbuf);
int mypid(void);
int myppid(void);
char *_getenv(const char *name);
size_t _strlen(const char *s);
int _strncmp(const char *s1, char *s2, int n);
#endif
/* END OF FILE */

