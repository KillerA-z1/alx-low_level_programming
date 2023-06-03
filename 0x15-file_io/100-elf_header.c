
#include <elf.h>
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
/**
 * print_magic - Prints magic of ELF file.
 * @magic: ELF magic numbers.
 *
 * Description: Prints the magic numbers of the ELF file header.
 */

void print_magic(unsigned char *magic)
{
	int i;

	printf("ELF Header:\n");
	printf("  Magic:   ");
	for (i = 0; i < EI_NIDENT; i++)
	{
		printf("%02x", magic[i]);
		i == EI_NIDENT - 1 ? printf("\n") : printf(" ");
	}
}
/**
 * print_class - Prints ELF class.
 * @class: ELF file.
 *
 * Description: Prints the ELF class (32-bit or 64-bit) of the ELF file.
 */

void print_class(unsigned char *class)
{
	printf("  Class:                             ");
	switch (class[EI_CLASS])
	{
	case ELFCLASSNONE:
		printf("none\n");
		break;
	case ELFCLASS32:
		printf("ELF32\n");
		break;
	case ELFCLASS64:
		printf("ELF64\n");
		break;
	default:
		printf("<unknown: %x>\n", class[EI_CLASS]);
		break;
	}
}
/**
 * print_data - Prints ELF data file.
 * @data: ELF file.
 *
 * Description: Prints the data encoding (endianess) of the ELF file.
 */
void print_data(unsigned char *data)
{
	printf("  Data:                              ");
	switch (data[EI_DATA])
	{
	case ELFDATANONE:
		printf("none\n");
		break;
	case ELFDATA2LSB:
		printf("2's complement, little endian\n");
		break;
	case ELFDATA2MSB:
		printf("2's complement, big endian\n");
		break;
	default:
		printf("<unknown: %x>\n", data[EI_DATA]);
		break;
	}
}
/**
 * print_version - Prints ELF version file.
 * @version: ELF file.
 *
 * Description: Prints the ELF version of the ELF file.
 */
void print_version(unsigned char *version)
{
	printf("  Version:                           %d", version[EI_VERSION]);
	switch (version[EI_VERSION])
	{
	case EV_CURRENT:
		printf(" (current)\n");
		break;
	default:
		printf("\n");
		break;
	}
}
/**
 * print_os_abi - Prints ELF OS/ABI file.
 * @os_abi: ELF file.
 *
 * Description: Prints the OS/ABI (operating system/ABI) of the ELF file.
 */
void print_os_abi(unsigned char *os_abi)
{
	printf("  OS/ABI:                            ");
	switch (os_abi[EI_OSABI])
	{
	case ELFOSABI_NONE:
		printf("UNIX - System V\n");
		break;
	case ELFOSABI_HPUX:
		printf("UNIX - HP-UX\n");
		break;
	case ELFOSABI_NETBSD:
		printf("UNIX - NetBSD\n");
		break;
	case ELFOSABI_LINUX:
		printf("UNIX - Linux\n");
		break;
	case ELFOSABI_SOLARIS:
		printf("UNIX - Solaris\n");
		break;
	case ELFOSABI_IRIX:
		printf("UNIX - IRIX\n");
		break;
	case ELFOSABI_FREEBSD:
		printf("UNIX - FreeBSD\n");
		break;
	case ELFOSABI_TRU64:
		printf("UNIX - TRU64\n");
		break;
	case ELFOSABI_ARM:
		printf("ARM\n");
		break;
	case ELFOSABI_STANDALONE:
		printf("Standalone App\n");
		break;
	default:
		printf("<unknown: %x>\n", os_abi[EI_OSABI]);
		break;
	}
}

/**
 * print_abi - Prinf ELF ABI version file.
 * @abi: ELF file.
 * Description:Prints the ABI version of the ELF file.
 */
void print_abi(unsigned char *abi)
{
	printf("  ABI Version:                       %d\n", abi[EI_ABIVERSION]);
}


/**
 * print_type - Print ELF type file.
 * @type: ELF type.
 * @class: ELF Class
 *
 * Description: Prints the type of the ELF file.
 */
void print_type(unsigned int type, unsigned char *class)
{
	if (class[EI_DATA] == ELFDATA2MSB)
		type >>= 8;

	printf("  Type:                              ");
	switch (type)
	{
	case ET_NONE:
		printf("NONE (None)\n");
		break;
	case ET_REL:
		printf("REL (Relocatable file)\n");
		break;
	case ET_EXEC:
		printf("EXEC (Executable file)\n");
		break;
	case ET_DYN:
		printf("DYN (Shared object file)\n");
		break;
	case ET_CORE:
		printf("CORE (Core file)\n");
		break;
	default:
		printf("<unknown: %x>\n", type);
		break;
	}
}

/**
 * print_entry - Print ELF entry.
 * @entry: ELF type.
 * @class: ELF Class
 *
 * Description: Prints the entry point address of the ELF file.
 */
void print_entry(unsigned long int entry, unsigned char *class)
{

	printf("  Entry point address:               ");
	if (class[EI_CLASS] == ELFCLASS32)
		printf("%#x\n", (unsigned int)entry);
	else
		printf("%#lx\n", entry);
}
/**
 * main - Displays the information contained in the ELF header at the
 *        start of an ELF file.
 * @argc: Number of arguments passed into the program.
 * @argv: Array of arguments passed.
 *
 * Return: 0 on success.
 *
 * Description: Opens and reads the ELF file header, and prints the relevant information.
 */
int main(int argc, char **argv)
{
	Elf64_Ehdr header;
	int fd;

	if (argc != 2 || argv[1] == NULL)
	{
		fprintf(stderr, "Usage: %s elf_filename\n", argv[0]);
		exit(1);
	}

	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
	{
		fprintf(stderr, "Error: Cannot read file %s\n", argv[1]);
		exit(1);
	}

	if (read(fd, &header, sizeof(Elf64_Ehdr)) == -1)
	{
		fprintf(stderr, "Error: Cannot read file %s\n", argv[1]);
		close(fd);
		exit(1);
	}

	print_magic(header.e_ident);
	print_class(header.e_ident);
	print_data(header.e_ident);
	print_version(header.e_ident);
	print_os_abi(header.e_ident);
	print_abi(header.e_ident);
	print_type(header.e_type, header.e_ident);
	print_entry(header.e_entry, header.e_ident);

	close(fd);
	return (0);
}
