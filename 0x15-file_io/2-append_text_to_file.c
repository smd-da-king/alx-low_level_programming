#include "main.h"

/**
 * append_text_to_file - Entry point
 * Description: Appends text at the end of a file
 * @filename: The name of the file to be read
 * @text_content: The NULL terminated string to add at the end of the file
 *
 * Return: 1 on sucess, -1 on failure
 */

int append_text_to_file(const char *filename, char *text_content)
{
	int td, my_write, i = 0;

	/* Checks if filename is NULL  and return -1 */
	if (!filename)
		return (-1);
	/* Opens file in append mode */
	td = open(filename, O_WRONLY | O_APPEND);
	if (td == -1)
		return (-1);
	/* If text_content is not empty, append it to file */
	if (text_content)
	{
		/* Counts the number of characters in text_content */
		while (text_content[i])
			i++;
		
/* Write text_content to file */
		my_write = write(td, text_content, i);
		/* Checls if writing to the file failed */
		if (my_write == -1)
			return (-1);
	}
	close(td);
	return (1);
}
