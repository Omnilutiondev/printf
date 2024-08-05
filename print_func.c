#include "main.h"

void print_buff(char buffer[], int *buff_indx);

/**
 * _printf – This is the printf function
 * @format: This is the format.
 * Return: The prntd chars.
 */
int _printf(const char *format, ...)
{
	int idx, prntd = 0, prntd_chars = 0;
	int flags, width, precision, size, buff_indx = 0;
	va_list list;
	char buffer[BUFF_SIZE];

	if (format == NULL)
		return (-1);

	va_start(list, format);

	for (idx = 0; format && format[idx] != '\0'; idx++)
	{
		if (format[idx] != '%')
		{
			buffer[buff_indx++] = format[idx];
			if (buff_indx == BUFF_SIZE)
				print_buff(buffer, &buff_indx);
			/* write(1, &format[idx], 1);*/
			prntd_chars++;
		}
		else
		{
			print_buff(buffer, &buff_indx);
			flags = get_flags(format, &idx);
			width = get_width(format, &idx, list);
			precision = get_precision(format, &idx, list);
			size = get_size(format, &idx);
			++idx;
			prntd = hndl_prnt(format, &idx, list, buffer,
				flags, width, precision, size);
			if (prntd == -1)
				return (-1);
			prntd_chars += prntd;
		}
	}

	print_buff(buffer, &buff_indx);

	va_end(list);

	return (prntd_chars);
}

/**
 * print_buff – This function prints the contents of the buffer if it exist
 * @buffer: This is an array of chars
 * @buff_indx: The index at which to add the next char, reps the length.
 */
void print_buff(char buffer[], int *buff_indx)
{
	if (*buff_indx > 0)
		write(1, &buffer[0], *buff_indx);

	*buff_indx = 0;
}


