#include "shell.h"

/**
 * _strcat - Concatenates two strings.
 * @dest: string that is added to.
 * @src: string that is added from.
 *
 * Return: Pointer to the concatenated string (dest).
 */
char *_strcat(char *dest, char *src)
{
int dest_len = 0;
int src_len = 0;

while (dest[dest_len] != '\0')
{
dest_len++;
}

while (src[src_len] != '\0')
{
dest[dest_len] = src[src_len];
dest_len++;
src_len++;
}

dest[dest_len] = '\0';

return (dest);
}

