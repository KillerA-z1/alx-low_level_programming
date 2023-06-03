#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <fcntl.h>
#include <unistd.h>
#include <elf.h>

/**
 * read_elf_header - reads the header of an elf
 * @fd: file descriptor
 * @elf_header: pointer to hold Elf32_Ehdr elements
 * Return: nothing
 **/
void read_elf_header(int fd, Elf32_Ehdr *elf_header)
{
	if (elf_header == NULL)
	{
		dprintf(STDERR_FILENO, "header null Unable to read elf\n");
		exit(98);
	}

	if (lseek(fd, 0, SEEK_SET) != 0)
	{
		dprintf(STDERR_FILENO, "offset Unable to read elf\n");
		exit(98);
	}

	if (read(fd, elf_header, sizeof(Elf32_Ehdr)) != sizeof(Elf32_Ehdr))
	{
		dprintf(STDERR_FILENO, "size of Unable to read elf\n");
		exit(98);
	}
}

/**
 * is_ELF - checks if it's an elf or not
 * @eh: pointer to hold Elf32_Ehdr elements
 * Return: 1 if it's an elf, else 0
 **/
bool is_ELF(Elf32_Ehdr eh)
{
	if (eh.e_ident[0] == ELFMAG0 &&
	    eh.e_ident[1] == ELFMAG1 &&
	    eh.e_ident[2] == ELFMAG2 &&
	    eh.e_ident[3] == ELFMAG3)
	{
		return true;
	}

	return false;
}

/**
 * print_typ - prints elf header type information
 * @eh: pointer to hold Elf32_Ehdr elements
 * Return: nothing
 **/
void print_typ(Elf32_Ehdr eh)
{
	printf("Type:                                           ");
	switch (eh.e_type)
	{
	case ET_NONE:
		printf("N/A (0x0)\n");
		break;

	case ET_REL:
		printf("REL (Relocatable file)\n");
		break;

	case ET_EXEC:
		printf("EXEC (Executable file)\n");
		break;

	case ET_DYN:
		printf("DYN (Shared Object file)\n");
		break;

	case ET_CORE:
		printf("CORE (Core file)\n");
		break;

	default:
		printf("<unknown: %x>\n", eh.e_type);
		break;
	}
}

/**
 * print_os - prints elf header OS/ABI information
 * @eh: pointer to Elf32_Ehdr elements
 * Return: nothing
 **/
void print_os(Elf32_Ehdr eh)
{
	printf("OS/ABI:                                         ");
	switch (eh.e_ident[EI_OSABI])
	{
	case ELFOSABI_SYSV:
		printf("UNIX - System V\n");
		break;

	case ELFOSABI_HPUX:
		printf("UNIX - HP-UX\n");
		break;

	case ELFOSABI_NETBSD:
		printf("UNIX - NetBSD\n");
		break;

	case ELFOSABI_LINUX:
		printf("UNIX - GNU\n");
		break;

	case ELFOSABI_SOLARIS:
		printf("UNIX - Solaris\n");
		break;

	case ELFOSABI_AIX:
		printf("UNIX - AIX\n");
		break;

	case ELFOSABI_IRIX:
		printf("UNIX - Irix\n");
		break;

	case ELFOSABI_FREEBSD:
		printf("UNIX - FreeBSD\n");
		break;

	case ELFOSABI_TRU64:
		printf("UNIX - TRU64\n");
		break;

	case ELFOSABI_MODESTO:
		printf("Novell Modesto\n");
		break;

	case ELFOSABI_OPENBSD:
		printf("UNIX - OpenBSD\n");
		break;

	case ELFOSABI_ARM:
		printf("ARM\n");
		break;

	case ELFOSABI_STANDALONE:
		printf("Standalone (embedded) application\n");
		break;

	default:
		printf("<unknown: %x>\n", eh.e_ident[EI_OSABI]);
		break;
	}
}

/**
 * print_clas - prints elf header class information
 * @eh: pointer to elf_header elements
 * Return: nothing
 **/
void print_clas(Elf32_Ehdr eh)
{
	printf("Class:                                          ");
	switch (eh.e_ident[EI_CLASS])
	{
	case ELFCLASS32:
		printf("ELF32\n");
		break;

	case ELFCLASS64:
		printf("ELF64\n");
		break;

	default:
		printf("Invalid class\n");
		break;
	}
}

/**
 * print_dta - prints elf header data information
 * @eh: pointer to elf_header elements
 * Return: nothing
 **/
void print_dta(Elf32_Ehdr eh)
{
	printf("Data:                                           ");
	switch (eh.e_ident[EI_DATA])
	{
	case ELFDATA2LSB:
		printf("2's complement, little endian\n");
		break;

	case ELFDATA2MSB:
		printf("2's complement, big endian\n");
		break;

	default:
		printf("Invalid ELF data\n");
		break;
	}
}

/**
 * print_vrsn - prints elf header version information
 * @eh: pointer to elf_header elements
 * Return: nothing
 **/
void print_vrsn(Elf32_Ehdr eh)
{
	printf("Version:                                        ");
	switch (eh.e_version)
	{
	case EV_NONE:
		printf("Invalid version\n");
		break;

	case EV_CURRENT:
		printf("1 (Current)\n");
		break;

	default:
		printf("<unknown: %x>\n", eh.e_version);
		break;
	}
}

/**
 * print_elf_header - helper function to print the elf header
 * @elf_header: pointer to elf_header elements
 * Return: nothing
 **/
void print_elf_header(Elf32_Ehdr elf_header)
{
	int i;

	printf("ELF Header:\n");
	printf("Magic:   ");

	for (i = 0; i < EI_NIDENT; i++)
	{
		printf("%2.2x ", elf_header.e_ident[i]);
	}
	printf("\n");

	print_clas(elf_header);
	print_dta(elf_header);
	print_vrsn(elf_header);
	print_os(elf_header);
	printf("ABI Version:                                    %u\n", elf_header.e_ident[EI_ABIVERSION]);
	print_typ(elf_header);
	printf("Entry point address:                            0x%x\n", elf_header.e_entry);
}

/**
 * main - displays the information contained in the ELF header
 * @argc: number of args
 * @argv: pointer to arg
 * Return: 0 on success or exit with 98 on failure
 **/
int main(int argc, char *argv[])
{
	int fd;
	Elf32_Ehdr eh;

	if (argc != 2)
	{
		dprintf(STDERR_FILENO, "Usage: %s <ELF_FILE>\n", argv[0]);
		exit(98);
	}

	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
	{
		dprintf(STDERR_FILENO, "Error: Unable to open %s\n", argv[1]);
		exit(98);
	}

	read_elf_header(fd, &eh);
	if (!is_ELF(eh))
	{
		dprintf(STDERR_FILENO, "Error: Not an ELF file\n");
		exit(98);
	}

	print_elf_header(eh);
	return 0;
}
