#include "shell.h"

/**
 * sh_strcpy - copies the string pointed to by src
 * @dest: copy destination
 * @src: copy source
 *
 * Return: the pointer to dest
 */

char *sh_strcpy(char *dest, char *src)
{
	int i = 0;

	while (*(src + i))
	{
		*(dest + i) = *(src + i);
		i++;
	}
	*(dest + i) = '\0';
	return (dest);
}
