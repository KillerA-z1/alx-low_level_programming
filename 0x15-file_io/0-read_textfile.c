#include "main.h"

/**
 * read_textfile -Reads a text file and prints it to the POSIX standard output.
 * @filename: A pointer to the name of the file.
 * @letters: The number of letters it should read and print.
 * Return: The actual number of letters it could read and print else
 *	return 0 when file can not be opened or read,filename is NULL
 *	and if write fails or does not write the expected amount of bytes.
 */

ssize_t read_textfile(const char *filename, size_t letters)
{
	ssize_t read_count, write_count;
	char *buffer;
	int fd;

	if (filename == NULL || letters <= 0)
		return (0);

	fd = open(filename, O_RDONLY);

	buffer = malloc(sizeof(char) * letters);
	if (buffer == NULL)
	{
		close(fd);
		return (0);
	}
	read_count = read(fd, buffer, letters);
	if (read_count == -1)
	{
		free(buffer);
		close(fd);
		return (0);
	}
	write_count = write(STDOUT_FILENO, buffer, read_count);
	if (write_count == -1 || write_count != read_count)
	{
		free(buffer);
		close(fd);
		return (0);
	}

	free(buffer);
	close(fd);
	return (write_count);
}
