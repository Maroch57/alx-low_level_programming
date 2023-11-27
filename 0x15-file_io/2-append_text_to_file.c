#include "main.h"
/**
 * append_text_to_file - appends text at the end of a file.
 *.
 * @filename: name of the file to be appended.
 * @text_content: NULL terminated string to be written to the file.
 * Return: 1 if successful, -1 on failure.
 */
int append_text_to_file(const char *filename, char *text_content)
{
	int rd, txt_write, lngth;

	if (filename == NULL)
		return (-1);
	if (text_content != NULL)
	{
		rd = open(filename, O_WRONLY | O_APPEND);
		if (rd == -1)
			return (-1);
		lngth = 0;
		while (*(text_content + lngth) != '\0')
			lngth++;
		txt_write = write(rd, text_content, lngth);
		if (txt_write == -1)
		{
			close(rd);
			write(STDOUT_FILENO, "fails", 5);
			return (-1);
		}
	}
	close(rd);
	return (1);
}
