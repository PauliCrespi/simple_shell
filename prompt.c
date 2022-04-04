#include "sshlib.h"

int prompt(void)
{
        size_t sizebuff = 32;
        char *buffer;
        int response = 0;
        char **vtptr;
        int i;

        while(response != -1)
        {
            buffer = (char *)malloc(sizeof(char) * sizebuff);
            if (buffer == NULL)
            {
                    perror("Unable to allocate buffer");
                    exit(1);
            }
            printf("$ ");
            response = getline(&buffer, &sizebuff, stdin);
            printf("%s", buffer);
            vtptr = tokenizer(buffer);
            while (vtptr[i])
            {
                printf("Token: %s\n", vtptr[i]);
                i++;
            }
<<<<<<< HEAD
	    _fork(vtptr);
	    i = 0;
	    free(buffer);
=======
            
            i = 0;
            free(buffer);
>>>>>>> 9080491225558f469c017b16bdfc865788c704fe
        }
        //write(STDIN_FILENO, "\n", 1);
        return (response);
}

