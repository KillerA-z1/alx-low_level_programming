#include "main.h"
#include <stdio.h>
#define BUFFER_SIZE 1024

/**
 * main - a program that copies the content of a file to another file..
 * @argc: The number of arguments passed to the program.
 * @argv: An array of pointers to the arguments.
 *
 * Return: 0 on success, or an exit status on failure.
 */
int main(int argc, char *argv[])
{
    int fd_from, fd_to;
    ssize_t bytes_read, bytes_written;
    char buffer[BUFFER_SIZE];

    /* Check for correct number of arguments */
    if (argc != 3)
    {
        dprintf(STDERR_FILENO, "Usage: cp file_from file_to\n");
        exit(97);
    }

    /* Open file_from for reading */
    fd_from = open(argv[1], O_RDONLY);
    if (fd_from == -1)
    {
        dprintf(STDERR_FILENO, "Error: Can't read from file %s\n", argv[1]);
        exit(98);
    }

    /* Open file_to for writing, create if it doesn't exist */
    fd_to = open(argv[2], O_WRONLY | O_CREAT | O_TRUNC, 0664);
    if (fd_to == -1)
    {
        dprintf(STDERR_FILENO, "Error: Can't write to %s\n", argv[2]);
        close(fd_from);
        exit(99);
    }

    /* Read from file_from and write to file_to */
    while ((bytes_read = read(fd_from, buffer, BUFFER_SIZE)) > 0)
    {
        bytes_written = write(fd_to, buffer, bytes_read);
        if (bytes_written == -1)
        {
            dprintf(STDERR_FILENO, "Error: Can't write to %s\n", argv[2]);
            close(fd_from);
            close(fd_to);
            exit(99);
        }
    }

    /* Check for read error */
    if (bytes_read == -1)
    {
        dprintf(STDERR_FILENO, "Error: Can't read from file %s\n", argv[1]);
        close(fd_from);
        close(fd_to);
        exit(98);
    }

    /* Close file descriptors */
    if (close(fd_from) == -1 || close(fd_to) == -1)
    {
        dprintf(STDERR_FILENO, "Error: Can't close fd\n");
        exit(100);
    }

    return (0);
}

