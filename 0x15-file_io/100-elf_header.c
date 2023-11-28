#include <elf.h>
#include "main.h"
#include <stdlib.h>
#include <stdio.h>
#define REV(h) ((h << 24) | (((h >> 16) << 24) >> 16) | \
(((h << 16) >> 24) << 16) | (h >> 24))
/**
* validate - validates the file to check if it is an ELF
* @check_ver: ELF struct
* return: NULL.
*/

void validate(unsigned char *check_ver)
{
	if (*(check_ver) == 0x7f && *(check_ver + 1) == 'E' &&
	    *(check_ver + 2) == 'L' && *(check_ver + 3) == 'F')
	{
		printf("ELF Header:\n");
	}
	else
	{
		dprintf(STDERR_FILENO, "Error: this file not is a valid ELF\n");
		exit(98);
	}
}

/**
* kadabra - prints a special no.
* @check_ver: ELF struct.
* return: NULL.
*/

void kadabra(unsigned char *check_ver)
{
	int i;
	int limit;

	limit = EI_NIDENT - 1;
	printf("  Magic:   ");
	for (i = 0; i < limit; i++)
		printf("%02x ", *(check_ver + i));
	printf("%02x\n", *(check_ver + i));
}

/**
* m_class - prints the ELF class.
* @check_ver: the ELF struct
* return: NULL.
*/

void m_class(unsigned char *check_ver)
{
	printf("  Class:                             ");
	if (check_ver[EI_CLASS] == ELFCLASSNONE)
		printf("This class is invalid\n");
	else if (check_ver[EI_CLASS] == ELFCLASS32)
		printf("ELF32\n");
	else if (check_ver[EI_CLASS] == ELFCLASS64)
		printf("ELF64\n");
	else
		printf("<unknown: %x>\n", check_ver[EI_CLASS]);
}

/**
* data_type - prints type of data.
* @check_ver: ELF struct.
* return: NULL.
*/

void data_type(unsigned char *check_ver)
{
	printf("  Data:                              ");
	if (check_ver[EI_DATA] == ELFDATANONE)
		printf("Unknown data format\n");
	else if (check_ver[EI_DATA] == ELFDATA2LSB)
		printf("2's complement, little endian\n");
	else if (check_ver[EI_DATA] == ELFDATA2MSB)
		printf("2's complement, big endian\n");
	else
		printf("<unknown: %x>\n", check_ver[EI_DATA]);
}

/**
* versn - prints file versiion.
* @check_ver: ELF struct.
* return: NULL.
*/

void versn(unsigned char *check_ver)
{
	printf("  Version:                           ");
	if (check_ver[EI_VERSION] == EV_CURRENT)
		printf("%i (current)\n", EV_CURRENT);
	else
		printf("%i\n", check_ver[EI_VERSION]);
}

/**
 * serious_osbi - prints the resp osabi.
 * @check_ver: the ELF struct
 * return: NULL.
 */
void serious_osbi(unsigned char *check_ver)
{
	printf("  OS/ABI:                            ");
	if (check_ver[EI_OSABI] == ELFOSABI_SYSV)
		printf("UNIX - System V\n");
	else if (check_ver[EI_OSABI] == ELFOSABI_HPUX)
		printf("UNIX - HP-UX\n");
	else if (check_ver[EI_OSABI] == ELFOSABI_NETBSD)
		printf("UNIX - NetBSD\n");
	else if (check_ver[EI_OSABI] == ELFOSABI_LINUX)
		printf("UNIX - Linux\n");
	else if (check_ver[EI_OSABI] == ELFOSABI_SOLARIS)
		printf("UNIX - Solaris\n");
	else if (check_ver[EI_OSABI] == ELFOSABI_IRIX)
		printf("UNIX - IRIX\n");
	else if (check_ver[EI_OSABI] == ELFOSABI_FREEBSD)
		printf("UNIX - FreeBSD\n");
	else if (check_ver[EI_OSABI] == ELFOSABI_TRU64)
		printf("UNIX - TRU64\n");
	else if (check_ver[EI_OSABI] == ELFOSABI_ARM)
		printf("ARM\n");
	else if (check_ver[EI_OSABI] == ELFOSABI_STANDALONE)
		printf("Standalone App\n");
	else
		printf("<unknown: %x>\n", check_ver[EI_OSABI]);
}

/**
* ttype - print the resp type.
* @check_ver: ELF struct.
* @k_type: data to compare and print.
* return: NULL.
*/

void ttype(unsigned int k_type, unsigned char *check_ver)
{
	check_ver[EI_DATA] == ELFDATA2MSB ? k_type = k_type >> 8 : k_type;

	printf("  Type:                              ");
	if (k_type == ET_NONE)
		printf("NONE (Unknown type)\n");
	else if (k_type == ET_REL)
		printf("REL (Relocatable file)\n");
	else if (k_type == ET_EXEC)
		printf("EXEC (Executable file)\n");
	else if (k_type == ET_DYN)
		printf("DYN (Shared object file)\n");
	else if (k_type == ET_CORE)
		printf("CORE (Core file)\n");
	else
		printf("<unknown: %x>\n", k_type);
}

/**
* entry_pt - print entry point.
* @check_ver: ELF struct.
* @p_entry: data to be printed.
* return: NULL.
*/

void entry_pt(unsigned int p_entry, unsigned char *check_ver)
{
	if (check_ver[EI_DATA] == ELFDATA2MSB)
		p_entry = REV(p_entry);

	printf("  Entry point address:               ");
	printf("%#x\n", (unsigned int)p_entry);
}

/**
* main - read a ELF file.
* @argc: the number of arguments.
* @argv: the arguments.
* section header: essential for understanding varous info about the ELF file.
* Return: 0 if successful.
*/

int main(int argc, char *argv[])
{
	int fd, _read, _close;
	Elf64_Ehdr *file;

	if (argc > 2 || argc < 2)
		dprintf(STDERR_FILENO, "Usage: error in # of args\n"), exit(98);
	file = malloc(sizeof(Elf64_Ehdr));
	if (file == NULL)
		dprintf(STDERR_FILENO, "error in allocate memory\n"), exit(98);
	fd = open(*(argv + 1), O_RDONLY);
	if (fd == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't read from file %s\n", *(argv + 1));
		exit(98);
	}
	_read = read(fd, file, sizeof(Elf64_Ehdr));
	if (_read == -1)
	{
		free(file);
		dprintf(STDERR_FILENO, "Error: Can't read from file %s\n", *(argv + 1));
		exit(98);
	}
	validate(file->e_ident);
	kadabra(file->e_ident);
	m_class(file->e_ident);
	data_type(file->e_ident);
	versn(file->e_ident);
	serious_osbi(file->e_ident);
	printf("  ABI Version:                       ");
	printf("%i\n", file->e_ident[EI_ABIVERSION]);
	ttype(file->e_type, file->e_ident);
	entry_pt(file->e_entry, file->e_ident);
	free(file);
	_close = close(fd);
	if (_close)
	{
		dprintf(STDERR_FILENO, "Error: Can't close fd\n");
		exit(98);
	}
	return (0);
}
