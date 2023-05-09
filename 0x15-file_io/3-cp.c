#include "main.h"

/**
 * _filcpy - copies the source file to destination.
 * @source: pointer to source document that will be copied.
 * @destination: pointer to the document which we will paste what we copied.
 */

void _filcpy(const char *source, const char *destination)
{
	int fd, temp_copies, read_bytes;
	char size[1024];

	fd = open(source, O_RDONLY);
	if (!source || fd == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't read from file %s\n", source);
		exit(98);
	}

	temp_copies = open(destination, O_CREAT | O_WRONLY | O_TRUNC, 0664);
	while ((read_bytes = read(fd, size, BUFFER_SIZE)) > 0)
	{
		if (write(temp_copies, size, read_bytes) != read_bytes || temp_copies == -1)
		{
			dprintf(STDERR_FILENO, "Error: Can't write to %s\n", destination);
			exit(99);
		}
	}

	if (close(fd) == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", fd);
		exit(100);
	}

	if (close(temp_copies) == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", temp_copies);
		exit(100);
	}

	if (read_bytes == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't read from file %s\n", source);
		exit(98);
	}
}
/**
 * main - Copies the contents of a file to another file.
 * @argc: The number of arguments supplied to the program.
 * @argv: An array of pointers to the arguments.
 * Return: 0 on success.
 */

int main(int argc, char **argv)
{
	if (argc != 3)
	{
		dprintf(STDERR_FILENO, "Usage: cp file_from file_to\n");
		exit(97);
	}
	_filcpy(argv[1], argv[2]);
	exit(0);
}

