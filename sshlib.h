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
int inline_ssh(int ac __attribute__((unused)), char **argv);
char **tokenizer(char *line, const char *sep);
void _fork(char **ptrbuf);
int manage_builtins(char *line);
int three_digits(char *line);
int four_digits(char *line);
void _getenv_all(void);
int mypid(void);
int myppid(void);
char *_getenv(const char *name);
int _strlen(const char *s);
int seplen(char *line, const char *sep);
char **_tokenize(char **line, const char *sep);
int _strncmp(const char *s1, char *s2, int n);
void _strcpy(char *dest, char *src);
int is_combined_cmd(char **vtline);
void clean_buffer(char **buf);
void cpy_argv_to_buf(char **buf, char **vtline, int mode);
int look_cmd_in_path(char **vtline, char **path_tokens, char **buf, int mode);

#endif
