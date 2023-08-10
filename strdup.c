#include "shell.h"
#include <stdlib.h>

/**
 * _strdup - Returns a pointer to a newly allocated space in memory,
 * which contains a copy of the string given as a parameter.
 * @str: string to be copied.
 * Return: Pointer to new allocated memory or NULL if malloc fails.
 */

char *_strdup(char *str)
{
char *str_new;
int i, j;

if (str == NULL)
{
return (NULL);
}
i = 0;
while (str[i] != '\0')
{
i++;
}

str_new = malloc(sizeof(*str_new) * i + 1);
if (str_new == NULL)
{
return (NULL);
}
for (j = 0; j < i; j++)
{
*(str_new + j) = str[j];
}
str_new[j] = '\0';

return (str_new);
}
