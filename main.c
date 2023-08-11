#include "shell.h"

/**
 * main - Main file for the shell which executes other functions.
 * @ac: Number of arguments
 * @argv: Array of arguments
 *
 * Return: 0, when successful and 1 if otherwise.
 */

int main(int ac, char **argv)
{
char *lineptr_cp = NULL, *lineptr = NULL;
char **tokenized_argv;
size_t n = 0;
ssize_t nchars_read; /* Holds the getline return value */
int status;
(void)ac;
while (1)
{
write(1, PROMPT, _strlen(PROMPT));
nchars_read = getline(&lineptr, &n, stdin);
/* Checks if the getline function failed, reached EOF or user used CTRL + D */
if (nchars_read == -1)
{
printf("Exiting shell....\n");
return (-1);
}
lineptr_cp = malloc(sizeof(char) * nchars_read);
if (lineptr_cp == NULL)
{
perror("tsh: memory allocation error");
return (-1);
}
/* copy lineptr to lineptr_copy */
sh_strcpy(lineptr_cp, lineptr);
/* Tokenizes input */
tokenized_argv = tokenize_input(lineptr, lineptr_cp, argv);
if (strcmp(tokenized_argv[0], "exit") == 0)
{
break; /* Terminate the loop and exit the shell */
}
/* Executes command */
status = process_command(tokenized_argv);
}
free(lineptr_cp);
free(lineptr);
return (status);
}

/**
 * process_command - Check current running process
 * @argv: a pointer array to command line arguments
 *
 * Return: 0, if successful.
 */

int process_command(char **argv)
{
pid_t pid = fork();

if (pid == 0)
{
execmd(argv);
exit(EXIT_SUCCESS);
}
else if (pid < 0)
{
perror("tsh: fork failed");
exit(EXIT_FAILURE);
}
else
{
int status;
waitpid(pid, &status, 0);
return (status);
}
}
