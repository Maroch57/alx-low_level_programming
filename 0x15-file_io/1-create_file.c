#include "main.h"

/**
 * create_file - fn creates a file.
 *
 * @filename: name of the file to be created.
 * @text_content: NULL terminated string to write to the file.
 * Return: 1 if successful, -1 on failure.
 */

int create_file(const char *filename, char *text_content)

{
	int rd, lngth;
	ssize_t txt_write;

	if (filename == NULL)
		return (-1);
	rd = open(filename, O_CREAT | O_WRONLY | O_TRUNC, 0600);
	if (rd == -1)
		return (-1);
	if (text_content != NULL)
	{
		lngth = 0;
		while (*(text_content + lngth) != '\0')
			lngth++;
		txt_write = write(rd, text_content, lngth);
		if (txt_write == -1)
		{
			write(1, "fails", 6);
			return (-1);
		}
	}
	close(rd);
	return (1);
}
