#ifndef SHELL_H
#define SHELL_H

#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>
/* Macros */
#define BUFFER_SIZE 1024
#define PROMPT "(OMONS_Shell) $ "

extern char **environ;

void execmd(char **argv);

/* main.c */
int process_command(char **argv);

/* _getline.c */
ssize_t sh_getline(char **buf, size_t *n, FILE *stream);
void var_line(char **line_buf, size_t *line_size,
char *buffer, size_t buf_size);

/* getenv.c */
char *sh_getenv(const char *name);

/* _realloc.c */
void *sh_realloc(void *ptr, unsigned int old_size, unsigned int new_size);

/* get_location.c */
char *get_location(char *command);
char *check_path(char *path_copy, char *command);

/* input_tokenizer.c */
char **tokenize_input(char *input, char *input_cp, char **argv);

/* strcpy.c */
char *sh_strcpy(char *dest, char *src);

/* strlen.c */
int _strlen(char *s);

/* strdup.c */
char *_strdup(char *str);

/* strcat.c */
char *_strcat(char *dest, char *src);

/* strncmp */
int _strncmp(const char *s1, const char *s2, size_t n);

/* strchr.c */
char *_strchr(char *s, char c);

#endif
