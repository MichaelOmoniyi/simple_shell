#include <stddef.h>

/**
 * _strncmp - Compares strings with a particular range number.
 * @s1: String 1 to be compared.
 * @s2: String 2 to be compared.
 * @n: Number to stop comparison.
 *
 * Return: 0, if successful
 */
int _strncmp(const char *s1, const char *s2, size_t n)
{
size_t i;

if (s1 == NULL || s2 == NULL)
{
return (0);
}
for (i = 0; i < n; i++)
{
if (s1[i] == '\0' || s2[i] == '\0')
{
return (s1[i] - s2[i]);
}

if (s1[i] != s2[i])
{
return (s1[i] - s2[i]);
}
}

return (0);
}

