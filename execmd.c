#include "shell.h"

/**
 * execmd - executes command path
 * @argv: an array of user input
 */

void execmd(char **argv)
{
char *command = NULL, *actual_command = NULL;

if (argv)
{
/* get the command */
command = argv[0];

/* Generate the path for the command */
actual_command = get_location(command);

/* execute the command with execve */
if (execve(actual_command, argv, NULL) == -1)
{
perror("Error:");
}
}
}
