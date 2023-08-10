#include "shell.h"

/**
 * _strchr - locates a character in a string
 * @s: a string
 * @c: character to be found
 * Return: Returns the character if found and NULL
 * if not found
 */

char *_strchr(char *s, char c)
{
int i;

for (i = 0; *s != '\0'; i++)
{
if (*s == c)
{
return (s);
}
s++;
}
if (*s == c)
{
return (s);
}
*s = 0;
return (s);
}
