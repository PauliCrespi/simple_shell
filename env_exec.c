#include "sshlib.h"

/**
 * main - 
 *
 * Return: Shell Status.
 */
int main(int ac, char **argv)
{
	int status, pid, i, j, exe, flag;
	char *buf[1024];
	char *path, *find, *strv;
	char **path_tokens, **cmd_tokens;
	struct stat sfile;
	
    
    // Copying Argv to Buffer // 
	i = 0;
	j = 1;
	while (argv[j] != NULL)
	{
		buf[i] = argv[j];
		j++;
		i++;
	}
	
	
	// Preparing the token to look for //
	i = 0;
	cmd_tokens = tokenizer2(buf[0], "/");
	while (cmd_tokens[i] != NULL)                                                      
	{   
	    find = cmd_tokens[i];
	    i++;                                                                    
	}
	
	
	// Getting the env and path to look in //
	flag = -1;
	i = 0;
	path = _getenv("PATH");
    path_tokens = tokenizer2(path, "=");
    path_tokens = tokenizer2(path_tokens[1], ":");
	while (path_tokens[i] != NULL)                                                      
	{   
	    strv = path_tokens[i];
	    strcat(strv, "/"); 
	    strcat(strv, find);                           
	    exe = stat(strv, &sfile);
		if (exe == 0)
		{
		    buf[0] = strv;
		    flag = 0;
		    break;
		} 
		i++;
	}
	                                                                    
	
	
	
	
    // FORK, EXECUTE AND WAIT //
    if (flag == 0)
    {
	    pid = fork();
	    if (pid == -1)
	    {
		    perror("Error");
		    return (1);
	    }
	    if (pid == 0)
	    {
		    //printf("Waiting for child proccess %d\n", pid);
		    printf("PID: %d\n", mypid());
		    printf("PPID: %d\n", myppid());
		    sleep(1);
		    if (execve(buf[0], buf, NULL) == -1)
		    {
			    perror("Error");
		    }
	    }
	    else
	    {
		    wait(&status);
		    printf("Status: %d\n", status);
	    }
	}
	else
	{
	    printf("ssh: command %s not found.\n", find);
	    return (-1);
	}
	
	return (0);
}
