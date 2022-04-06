<h1 align="center">
SIMPLE SHELL PROJECT
</h1>

<h2 align="center">
By: Alex Senges and Paulina Crespi
</h2>

# INTRODUCTION:
Using C language we aimed to simulate UNIX Shell creating our own functions and files. 0x16. C - Simple Shell is Holberton's first trimester's final project. Based on command line inputs this shell will read and implement commands in both interactive and noninteractive mode.

## PROTOTYPE:

int main(int ac, char **av);

### INPUT: 

Command line arguments.

### RETURN: 

Int 0 if the function works or -1 if error.

### FUNCTION LIBRARY:

  sshlib.h

### OTHER FUNCTIONS WE CREATED:

- int prompt(void);

- char **tokenizer(char *line);

- char **tokenizer2(char *line, char *sep);

- char *_getenv(const char *name);

- size_t _strlen(const char *s);

- int _strncmp(const char *s1, char *s2, int n);

- pid_t  _fork(char **ptrbuf);

- int mypid(void);

- int myppid(void);



### SYSTEM CALLS AND FUNCTIONS FORM THE STANDARD LIB WE USED:

- fork (man 2 fork)

- free (man 3 free)

- getline (man 3 getline)

- getpid (man 2 getpid)

- malloc (man 3 malloc)

- strtok (man 3 strtok)

- wait (man 2 wait)

- perror (man 3 perror)

## TO EXECUTE THIS SHELL:

### IN THE INTERACTIVE MODE EXAMPLE:

A prompt will be printed and will wait for the command line.

$ ./hsh
($) /bin/ls
hsh main.c shell.c
($)
($) exit
$


### NON-INTERACTIVE MODE EXAMPLE:

$ echo "/bin/ls" | ./hsh
hsh main.c shell.c test_ls_2
$
$ cat test_ls_2
/bin/ls
/bin/ls
$
$ cat test_ls_2 | ./hsh
hsh main.c shell.c test_ls_2
hsh main.c shell.c test_ls_2
$


## HOW THE SHELL WORKS:


1. READ LINE

2. TOKENIZE

Separate inputed arguments.

3. INTERPRET AND VALIDATE

Search for the inputed command and its path. If it does not exist notify the user.

4. EXECUTE 

Fork to create a child process to execute the command, if child process is not created ait for it. Then execute command.


## COMPILATION:

Compiled on Ubuntu 14.04 LTS with gcc 4.8.4 (C90).

CODE:

gcc -Wall -Werror -Wextra -pedantic -std=gnu89 *.c -o hsh


## MANUAL:

TO ACCESS THE FUNCTIONS MANUAL TYPE:

man man_1_simple_shell

## PROJECT'S BLOG:

What happens when you type `ls -l *.c` in the shell?

link to blog

## AUTHORS:

- * **Alex Senges** - [Alex Senges] (https://github.com/asenges)
- * **Paulina Crespi** - [PauliCrespi](https://github.com/PauliCrespi)

