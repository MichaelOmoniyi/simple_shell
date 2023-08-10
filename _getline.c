#include "shell.h"

/**
 * var_line - assigns the line var for get_line
 * @line_buf: Buffer that store the input str
 * @buffer: str that is been called to line
 * @line_size: size of line
 * @buf_size: size of buffer
 */
void var_line(char **line_buf, size_t *line_size,
char *buffer, size_t buf_size)
{

	if (*line_buf == NULL)
	{
		if  (buf_size > BUFFER_SIZE)
			*line_size = buf_size;

		else
			*line_size = BUFFER_SIZE;
		*line_buf = buffer;
	}
	else if (*line_size < buf_size)
	{
		if (buf_size > BUFFER_SIZE)
			*line_size = buf_size;
		else
			*line_size = BUFFER_SIZE;
		*line_buf = buffer;
	}
	else
	{
		sh_strcpy(*line_buf, buffer);
		free(buffer);
	}
}
/**
 * sh_get_line - Read inpt from stream
 * @buf: buffer that stores the input
 * @n: size of lineptr
 * @stream: stream to read from
 * Return: The number of bytes
 */
ssize_t sh_get_line(char **buf, size_t *n, FILE *stream)
{
	int i;
	static ssize_t prompt;
	ssize_t retval;
	char *buffer;
	char t = 'z';

	if (prompt == 0)
		fflush(stream);
	else
		return (-1);
	prompt = 0;

	buffer = malloc(sizeof(char) * BUFFER_SIZE);
	if (buffer == 0)
		return (-1);
	while (t != '\n')
	{
		i = read(STDIN_FILENO, &t, 1);
		if (i == -1 || (i == 0 && prompt == 0))
		{
			free(buffer);
			return (-1);
		}
		if (i == 0 && prompt != 0)
		{
			prompt++;
			break;
		}
		if (prompt >= BUFFER_SIZE)
			buffer = sh_realloc(buffer, prompt, prompt + 1);
		buffer[prompt] = t;
		prompt++;
	}
	buffer[prompt] = '\0';
	var_line(buf, n, buffer, prompt);
	retval = prompt;
	if (i != 0)
		prompt = 0;
	return (retval);
}
