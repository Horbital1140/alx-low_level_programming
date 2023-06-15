#include <elf.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

void check_fil_e(unsigned char *fe_ident);
void print_ma_gi_c(unsigned char *fe_ident);
void print_cla_ss(unsigned char *fe_ident);
void print_da_ta_s(unsigned char *fe_ident);
void print_ver_sion_s(unsigned char *fe_ident);
void print_a_bi_s(unsigned char *fe_ident);
void print_o_sab_i(unsigned char *fe_ident);
void print_ty_pe(unsigned int ty_pe, unsigned char *fe_ident);
void print_ent_ry(unsigned long int ent_ry, unsigned char *fe_ident);
void close_fil_e(int fil_e);

/**
 * check_fil_e - Checks_if_file is an ELF_fil_e.
 * @fe_ident: pointer to_array containing_the ELF magic n_umbers.
 *
 * Description: If_file is not_an_ELF file - exit code 98.
 */
void check_fil_e(unsigned char *fe_ident)
{
	int index;

	for (index = 0; index < 4; index++)
	{
		if (fe_ident[index] != 127 &&
		    fe_ident[index] != 'E' &&
		    fe_ident[index] != 'L' &&
		    fe_ident[index] != 'F')
		{
			dprintf(STDERR_FILENO, "Error: Not an ELF file\n");
			exit(98);
		}
	}
}

/**
 * print_ma_gi_c - Print_magic numbers of_ELF_header.
 * @fe_ident: pointer_to an array containing_the ELF magic_numbers.
 *
 * Description: Magic_numbers are separated_by_spaces.
 */
void print_ma_gi_c(unsigned char *fe_ident)
{
	int index;

	printf("  Magic:   ");

	for (index = 0; index < EI_NIDENT; index++)
	{
		printf("%02x", fe_ident[index]);

		if (index == EI_NIDENT - 1)
			printf("\n");
		else
			printf(" ");
	}
}

/**
 * print_cla_ss - Print_the class_of an ELF_header.
 * @fe_ident: pointer to_an array containing_the ELF_class.
 */
void print_cla_ss(unsigned char *fe_ident)
{
	printf("  Class:                             ");

	switch (fe_ident[EI_CLASS])
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
		printf("<unknown: %x>\n", fe_ident[EI_CLASS]);
	}
}

/**
 * print_da_tas - Print_the_data of an ElF_header.
 * @fe_ident: pointer_to an array_containing the_ELF class.
 */
void print_da_tas(unsigned char *fe_ident)
{
	printf("  Data:                              ");

	switch (fe_ident[EI_DATA])
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
		printf("<unknown: %x>\n", fe_ident[EI_CLASS]);
	}
}

/**
 * print_ver_sions - Prints the_version of a_ ELF_header.
 * @fe_ident: pointer_to an array contain_ng the ELF_version.
 */
void print_ver_sions(unsigned char *fe_ident)
{
	printf("  Version:                           %d",
	       fe_ident[EI_VERSION]);

	switch (fe_ident[EI_VERSION])
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
 * print_o_sab_i - Print_the OS/ABI of an ELF_header.
 * @fe_ident: A pointer to an_array containing_the ELF_version.
 */
void print_o_sab_i(unsigned char *fe_ident)
{
	printf("  OS/ABI:                            ");

	switch (fe_ident[EI_OSABI])
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
		printf("<unknown: %x>\n", fe_ident[EI_OSABI]);
	}
}

/**
 * print_a_bi_s - Print_the ABI version of an ELF_header.
 * @fe_ident: pointer to an_array containing the_ELF ABI version.
 */
void print_a_bi_s(unsigned char *fe_ident)
{
	printf("  ABI Version:                       %d\n",
	       fe_ident[EI_ABIVERSION]);
}

/**
 * print_ty_pe - Print_the type of_an ELF header.
 * @ty_pe: The_ELF_type.
 * @fe_ident: pointer to_an_array containing_the ELF class.
 */
void print_ty_pe(unsigned int ty_pe, unsigned char *fe_ident)
{
	if (fe_ident[EI_DATA] == ELFDATA2MSB)
		ty_pe >>= 8;

	printf("  Type:                              ");

	switch (ty_pe)
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
		printf("<unknown: %x>\n", ty_pe);
	}
}

/**
 * print_ent_ry - Print_the entry point_of_an ELF header.
 * @ent_ry: The address_of the ELF entry_point.
 * @fe_ident: pointer to_an array containing_the ELF class.
 */
void print_ent_ry(unsigned long int ent_ry, unsigned char *fe_ident)
{
	printf("  Entry point address:               ");

	if (fe_ident[EI_DATA] == ELFDATA2MSB)
	{
		ent_ry = ((ent_ry << 8) & 0xFF00FF00) |
			  ((ent_ry >> 8) & 0xFF00FF);
		ent_ry = (ent_ry << 16) | (ent_ry >> 16);
	}

	if (fe_ident[EI_CLASS] == ELFCLASS32)
		printf("%#x\n", (unsigned int)ent_ry);

	else
		printf("%#lx\n", ent_ry);
}

/**
 * close_fil_e - Close_an ELF file.
 * @fil_e: The file_descriptor_of the_ELF file.
 *
 * Description: If the file_cannot be_closed - exit code 98.
 */
void close_fil_e(int fil_e)
{
	if (close(fil_e) == -1)
	{
		dprintf(STDERR_FILENO,
			"Error: Can't close fd %d\n", fil_e);
		exit(98);
	}
}

/**
 * main - Displays the information contained in the
 *        ELF header at the start of an ELF file.
 * @argc: The number of arguments supplied to the program.
 * @argv: An array of pointers to the arguments.
 *
 * Return: 0 on success.
 *
 * Description: If the file is not an ELF File or
 *              the function fails - exit code 98.
 */
int main(int __attribute__((__unused__)) argc, char *argv[])
{
	Elf64_Ehdr *header;
	int o, r;

	o = open(argv[1], O_RDONLY);
	if (o == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't read file %s\n", argv[1]);
		exit(98);
	}
	header = malloc(sizeof(Elf64_Ehdr));
	if (header == NULL)
	{
		close_fil_e(o);
		dprintf(STDERR_FILENO, "Error: Can't read file %s\n", argv[1]);
		exit(98);
	}
	r = read(o, header, sizeof(Elf64_Ehdr));
	if (r == -1)
	{
		free(header);
		close_elf(o);
		dprintf(STDERR_FILENO, "Error: `%s`: No such file\n", argv[1]);
		exit(98);
	}

	check_fil_e(header->e_ident);
	printf("ELF Header:\n");
	print_ma_gi_c(header->e_ident);
	print_cla_ss(header->e_ident);
	print_da_tas(header->e_ident);
	print_ver_sion_s(header->f_ident);
	print_o_sab_i(header->e_ident);
	print_a_bi_s(header->e_ident);
	print_ty_pe(header->ty_pe, header->e_ident);
	print_ent_ry(header->ent_ry, header->e_ident);

	free(header);
	close_elf(o);
	return (0);
}
