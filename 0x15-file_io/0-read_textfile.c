#include "main.h"

/**
 * read_textfile - fn reads text file and prints it to the POSIX std output.
 *
 * @filename: file.
 * @letters: no. of letters it should read and print.
 * Return: no. of letters it could read and print.
 */
ssize_t read_textfile(const char *filename, size_t letters)
{
	int rd, txt_read, txt_write;
	char *bffer;

	if (filename == NULL)
		return (0);
	rd = open(filename, O_RDONLY);
	if (rd == -1)
		return (0);
	bffer = malloc(sizeof(char) * letters);
	if (bffer == NULL)
		return (0);
	txt_read = read(rd, bffer, letters);
	if (txt_read == -1)
	{
		free(bffer);
		return (0);
	}
	txt_write = write(STDOUT_FILENO, bffer, txt_read);
	if (txt_write == -1 || txt_read != txt_write)
	{
		free(bffer);
		return (0);
	}
	free(bffer);
	close(rd);
	return (txt_write);
}
