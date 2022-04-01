#include "sshlib.h"


int prompt(void)
{
        size_t sizebuff = 32;
        char *buffer;
        int response = 0;
        
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
            tokenizer(buffer);
            free(buffer);
        }
        //write(STDIN_FILENO, "\n", 1);
        return (response);
}

