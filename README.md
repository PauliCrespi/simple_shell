<h1 align="center">
SIMPLE SHELL PROJECT
</h1>

<h2 align="center">
By: Alex Senges and Paulina Crespi
</h2>

##INTRODUCTION:
Using C language we aimed to simulate UNIX Shell creating our own functions and files. 0x16. C - Simple Shell is Holberton's first trimester's final project. Based on command line inputs this shell will read and implement commands in both interactive and noninteractive mode.

#PROTOTYPE:

int main(int ac, char **av);

Input: 

Command line arguments.

Return: 

Int 0 if the function works or -1 if error.

FUNCTION LIBRARY:

  sshlib.h

OTHER FUNCTIONS WE CREATED:

int prompt(void);

char **tokenizer(char *line);

char **tokenizer2(char *line, char *sep);

char *_getenv(const char *name);

size_t _strlen(const char *s);

int _strncmp(const char *s1, char *s2, int n);

pid_t  _fork(char **ptrbuf);

int mypid(void);

int myppid(void);



SYSTEM CALLS AND FUNCTIONS FORM THE STANDARD LIB WE USED:

- fork (man 2 fork)

- free (man 3 free)

- getline (man 3 getline)

- getpid (man 2 getpid)

- malloc (man 3 malloc)

- strtok (man 3 strtok)

- wait (man 2 wait)

- perror (man 3 perror)

# HOW THE SHELL WORKS:


1. READ LINE

2. TOKENIZE

Separate inputed arguments.

3. INTERPRET AND VALIDATE

Search for the inputed command and its path. If it does not exist notify the user.

4. EXECUTE 

Fork to create a child process to execute the command, if child process is not created ait for it. Then execute command.


#COMPILATION:

Code:

gcc -Wall -Werror -Wextra -pedantic -std=gnu89 *.c -o hsh

#HOW THE FUNCTION WORKS:

#MANUAL:

TO ACCESS THE FUNCTIONS MANUAL TYPE:

man man_1_simple_shell

#PROJECT'S BLOG:

What happens when you type `ls -l *.c` in the shell?

link to blog

#AUTHORS:

- * **Alex Senges** - [asenges] (https://github.com/asenges)
- * **Paulina Crespi** - [PauliCrespi](https://github.com/PauliCrespi)

