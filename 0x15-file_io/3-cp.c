#include "main.h"

/**
 * _error - reads a file.
 * @y: err number.
 * @filename: name of the file.
 */

void _error(int y, char *filename)

{
	if (y == 98)
	{
		dprintf(STDERR_FILENO, "Error: Can't read from file %s\n", filename);
		exit(98);
	}
	if (y == 99)
	{
		dprintf(STDERR_FILENO, "Error: Can't write to %s\n", filename);
		exit(99);
	}
}
/**
 * cpy - Copies the content of a file to another file.
 * @init_file: Name of the source file.
 * @final_file: Name of the destination file.
 * Return: 1 if successful, -1 if it fails.
 */
void cpy(char *init_file, char *final_file)
{
	int rd_read, rds_read, rd_write, rds_write;
	char *bffer[1024];

	/* READ */
	rd_read = open(init_file, O_RDONLY);
	if (rd_read < 0)
		_error(98, init_file);
	/* WRITE */
	rd_write = open(final_file, O_CREAT | O_WRONLY | O_TRUNC, 0664);
	if (rd_write < 0)
	{
		close(rd_read);
		_error(99, final_file);
	}
	do {
		/* READ */
		rds_read = read(rd_read, bffer, 1024);
		if (rds_read < 0)
			_error(98, init_file);
		/* WRITE */
		rds_write = write(rd_write, bffer, rds_read);
		if (rds_write < rds_read)
			_error(99, final_file);
	}	while (rds_write == 1024);
	if (close(rd_read) < 0)
	{
		dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", rd_read);
		close(rd_write);
		exit(100);
	}
	if (close(rd_write) < 0)
	{
		dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", rd_write);
		exit(100);
	}
}
/**
 * main - copies content of a file to another.
 * @jk: arg count.
 * @fg: arg values.
 * Return: 0 if successful else -1 if unsuccessful..
 */
int main(int jk, char *fg[])
{
	if (jk != 3)
	{
		dprintf(STDERR_FILENO, "Usage: cpy file_from file_to\n");
		exit(97);
	}
	cpy(fg[1], fg[2]);
	return (0);
}
