#include "main.h"

void print_buff(char buffer[], int *buff_indx);

/**
 * _printf – This is the printf function
 * @format: This is the format.
 * Return: The printed chars.
 */
int _printf(const char *format, ...)
{
	int idx, printed = 0, printed_chars = 0;
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
			printed_chars++;
		}
		else
		{
			print_buff(buffer, &buff_indx);
			flags = get_flags(format, &idx);
			width = get_width(format, &idx, list);
			precision = get_precision(format, &idx, list);
			size = get_size(format, &idx);
			++idx;
			printed = handle_print(format, &idx, list, buffer,
				flags, width, precision, size);
			if (printed == -1)
				return (-1);
			printed_chars += printed;
		}
	}

	print_buff(buffer, &buff_indx);

	va_end(list);

	return (printed_chars);
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


