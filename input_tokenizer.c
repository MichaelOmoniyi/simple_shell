#include "shell.h"

/**
 * tokenize_input - Breaks users input into tokens.
 * @input: User's input.
 * @input_cp: Copy of user's input.
 * @argv: Array of arguments passed into the main function.
 *
 * Return: An array of tokens.
 */

char **tokenize_input(char *input, char *input_cp, char **argv)
{
const char *delim = " \n";
int num_tokens = 0;
char *token;
int i;

token = strtok(input, delim);
/* Calculate total number of words */
while (token != NULL)
{
num_tokens++;
token = strtok(NULL, delim);
}
num_tokens++;

argv = malloc(sizeof(char) * num_tokens);

/* Store each token in the argv array */
token = strtok(input_cp, delim);
for (i = 0; token != NULL; i++)
{
argv[i] = malloc(sizeof(char) * _strlen(token));
sh_strcpy(argv[i], token);

token = strtok(NULL, delim);
}
argv[i] = NULL;

return (argv);
}
