#include "sshlib.h"

char **tokenizer(char *line, const char *sep)
{
    char **tokens = malloc(sizeof(char *));
    *tokens = NULL;
    size_t n = 1;
    int success;

    char *p = strtok(line, sep);
    if (p != NULL)
        success = 1;
    else
        success = 0;

    while (success)
    {
        char **tmp = realloc(tokens,(n + 1) * sizeof(char *));
        if (tmp == NULL)
        {
            free(tokens);
            tokens = NULL;
            success = 0;
        }
        else
        {
            tokens = tmp;
            tokens[n - 1] = p;
            tokens[n] = NULL;
            ++n;
            p = strtok(NULL, sep);
            if (p != NULL)
                success = 1;
            else
                success = 0;

        }
    }
    return (tokens);
}
