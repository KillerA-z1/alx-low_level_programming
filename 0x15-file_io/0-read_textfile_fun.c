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
	FILE *fp;
	size_t count = 0;
	int c;

	if (filename == NULL || letters <= 0)
		return (0);

	fp = fopen(filename, "r");

	while ((c = fgetc(fp)) != EOF && count < letters)
	{
		putchar(c);
		count++;
	}
	if (count <= letters)
	fclose(fp);
	return (count);
}
