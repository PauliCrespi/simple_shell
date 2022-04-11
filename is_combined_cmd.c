#include "sshlib.h"
/**
 *is_combined_cmd - function
 *@vtline : command line
 *Return: flag
 */
int is_combined_cmd(char **vtline)
{
    int i = 0, flag = -1;
    
    for (i = 0; i < _strlen(vtline[0]); i++)
    {
        if ((vtline[0][i] == '.' && vtline[0][i+1] == '/') || vtline[0][i] == '/')
        {
            flag = 0;
            break;
        }
        else
        {
            flag = -1;
        }    
     }
     return (flag);
}
