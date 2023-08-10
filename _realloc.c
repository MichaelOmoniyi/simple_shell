#include "shell.h"
#include <stdlib.h>

/**
 * sh_realloc - reallocates a memory block using malloc and free.
 * @ptr: pointer to the memory previously allocated
 * @old_size: Old memory size.
 * @new_size: New memory size.
 * Return: Pointer to newly allocated memory block.
 */

void *sh_realloc(void *ptr, unsigned int old_size, unsigned int new_size)
{
char *ptr_2, *ptr_1;
unsigned int i;

if (new_size == old_size)
{
return (ptr);
}
if (new_size == 0 && ptr)
{
free(ptr);
return (NULL);
}
if (!ptr)
{
return (malloc(new_size));
}

ptr_2 = malloc(new_size);
if (ptr_2 == NULL)
{
return (NULL);
}
ptr_1 = ptr;

if (new_size > old_size)
{
for (i = 0; i < old_size; i++)
{
ptr_2[i] = ptr_1[i];
}
}
if (new_size < old_size)
{
for (i = 0; i < new_size; i++)
{
ptr_2[i] = ptr_1[i];
}
}
free(ptr);
return (ptr_2);
}
