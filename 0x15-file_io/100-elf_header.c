#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <fcntl.h>
#include <unistd.h>

#include <elf.h>

/**
 * read_elf_header - Reads the ELF header from the given file descriptor.
 * @fd: The file descriptor of the ELF file.
 * @elf_header: Pointer to the Elf32_Ehdr struct to store the ELF header.
 *
 * Return: 0 on success, -1 on failure.
 */
int read_elf_header(int fd, Elf32_Ehdr *elf_header)
{
	if (read(fd, elf_header, sizeof(Elf32_Ehdr)) != sizeof(Elf32_Ehdr))
	{
		dprintf(STDERR_FILENO, "Error: Unable to read ELF header\n");
		return (-1);
	}
	return (0);
}

/**
 * print_elf_field - Prints an ELF field name and its corresponding value.
 * @field_name: The name of the ELF field.
 * @field_value: The value of the ELF field.
 */
void print_elf_field(const char *field_name, unsigned int field_value)
{
	printf("%-20s", field_name);
	printf("%#010x\n", field_value);
}

/**
 * main - Entry point of the program.
 * @argc: The number of command-line arguments.
 * @argv: An array of command-line argument strings.
 *
 * Return: 0 on success, 1 on failure.
 */
int main(int argc, char *argv[])
{
	int fd;
	Elf32_Ehdr elf_header;

	if (argc != 2)
	{
		dprintf(STDERR_FILENO, "Usage: %s <ELF file>\n", argv[0]);
		return (1);
	}

	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
	{
		dprintf(STDERR_FILENO, "Error: Unable to open file '%s'\n", argv[1]);
		return (1);
	}

	if (read_elf_header(fd, &elf_header) == -1)
	{
		close(fd);
		return (1);
	}

	printf("ELF Header:\n");
	print_elf_field("Magic:", elf_header.e_ident[EI_MAG0]);
	print_elf_field("", elf_header.e_ident[EI_MAG1]);
	print_elf_field("", elf_header.e_ident[EI_MAG2]);
	print_elf_field("", elf_header.e_ident[EI_MAG3]);
	print_elf_field("Class:", elf_header.e_ident[EI_CLASS]);
	print_elf_field("Data:", elf_header.e_ident[EI_DATA]);
	print_elf_field("Version:", elf_header.e_ident[EI_VERSION]);
	print_elf_field("OS/ABI:", elf_header.e_ident[EI_OSABI]);
	print_elf_field("ABI Version:", elf_header.e_ident[EI_ABIVERSION]);
	print_elf_field("Type:", elf_header.e_type);
	print_elf_field("Entry point address:", elf_header.e_entry);

	close(fd);
	return (0);
}
