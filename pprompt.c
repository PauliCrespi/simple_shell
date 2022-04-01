#include <stdio.h>
#include <stdlib.h>
int main()
{
        size_t sizebuff = 32;
        char *buffer;

        buffer = (char *)malloc(sizeof(char) * sizebuff);
        if (buffer == NULL)
        {
                perror("Unable to allocate buffer");
                exit(1);
        }
        printf("$ ");
        getline(&buffer, &sizebuff, stdin);
        printf("%s", buffer);
        return(0);
}
