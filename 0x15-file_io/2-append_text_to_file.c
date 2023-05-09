#include "main.h"

/**
 * append_text_to_file - Function that appends text at the end of a file.
 * @filename: A pointer to the name of the file.
 * @text_content: A pointer to a string to append to the file.
 *
 * Return: 1 on success and -1 on failure,also if filename is NULL.
 */
int append_text_to_file(const char *filename, char *text_content)
{
	int fd, len = 0;

	if (filename == NULL)
		return (-1);

	if (text_content != NULL)
	{
		while (text_content[len])
			len++;
	}

	fd = open(filename, O_WRONLY | O_APPEND);
	if (fd == -1)
		return (-1);

	write(fd, text_content, len);

	if (!fd)
	{
		close(fd);
		return (-1);
	}

	close(fd);

	return (1);
}
