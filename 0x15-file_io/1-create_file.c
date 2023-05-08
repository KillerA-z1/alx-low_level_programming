#include "main.h"

/**
 * create_file - Function that creates a file.
 * @filename: A pointer to the name of the file to create.
 * @text_content: A pointer to a string to write to the file.
 *
 * Return: 1 on success and -1 on failure,also if filename is NULL.
 */
int create_file(const char *filename, char *text_content)
{
	int fd, len = 0;

	if (filename == NULL || text_content == NULL)
		return (-1);

	if (text_content != NULL)
	{
		while (text_content[len])
			len++;
	}

	fd = open(filename, O_CREAT | O_WRONLY | O_TRUNC, 0600);
	if (fd == -1)
	{
		close(fd);
		return (-1);
	}
	if (write(fd, text_content, len) != len)
	{
		close(fd);
		return (-1);
	}

	close(fd);
	return (1);
}
