#include "shell.h"

/**
 * check_path - Checks for the path of the command
 * @path_copy: Copy of environment variable
 * @command: Inputed command
 *
 * Return: The command path or NULL if unsuccesful
 */

char *check_path(char *path_copy, char *command)
{
char *path_token, *file_path;
struct stat buffer;
int directory_length, command_length, file_path_length;

path_token = strtok(path_copy, ":");

while (path_token != NULL)
{
directory_length = _strlen(path_token);
command_length = _strlen(command);
file_path_length = directory_length + command_length + 2;

file_path = malloc(file_path_length);
if (file_path == NULL)
{
perror("tsh: Memory allocation error");
free(path_copy);
return (NULL);
}

sh_strcpy(file_path, path_token);
_strcat(file_path, "/");
_strcat(file_path, command);

if (stat(file_path, &buffer) == 0)
{
free(path_copy);
return (file_path);
}

free(file_path);
path_token = strtok(NULL, ":");
}

free(path_copy);

return (NULL);
}

/**
 * get_location - This gets the file path of the command.
 * @command: The command to be executed.
 *
 * Return: The path of the command or NULL if not found.
 */
char *get_location(char *command)
{
char *path = sh_getenv("PATH");
char *path_created, *path_copy;

if (command[0] == '/')
{
if (access(command, F_OK) == 0)
{
return (_strdup(command));
}
else
{
return (NULL);
}
}
else
{
if (path == NULL)
{
perror("tsh: Failed to get PATH environment variable");
return (NULL);
}

path_copy = _strdup(path);
if (path_copy == NULL)
{
perror("tsh: Memory allocation error");
return (NULL);
}

path_created =  check_path(path_copy, command);
return (path_created);
}
}

