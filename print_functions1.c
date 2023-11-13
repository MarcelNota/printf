#include "main.h"

/* printing the number unsigned */
/**
 * print_unsigned - displays the number
 * @types: arguments
 * @buffer: the array
 * @flags: flags
 * @width: the widht
 * @precision: the precision
 * @size: the size
 * Return: chars
 */
int print_unsigned(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	int i = BUFF_SIZE - 2;
	unsigned long int num = va_arg(types, unsigned long int);

	num = convert_size_unsgnd(num, size);

	if (num == 0)
		buffer[i--] = '0';

	buffer[BUFF_SIZE - 1] = '\0';

	while (num > 0)
	{
		buffer[i--] = (num % 10) + '0';
		num /= 10;
	}

	i++;

	return (write_unsgnd(0, i, buffer, flags, width, precision, size));
}

/* printing number in oct */
/**
 * print_octal - printing number 
 * @types: arguments
 * @buffer: array
 * @flags: flags
 * @width: width
 * @precision: the precision
 * @size: the size
 * Return: the number
 */
int print_octal(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{

	int i = BUFF_SIZE - 2;
	unsigned long int num = va_arg(types, unsigned long int);
	unsigned long int init_num = num;

	UNUSED(width);

	num = convert_size_unsgnd(num, size);

	if (num == 0)
		buffer[i--] = '0';

	buffer[BUFF_SIZE - 1] = '\0';

	while (num > 0)
	{
		buffer[i--] = (num % 8) + '0';
		num /= 8;
	}

	if (flags & F_HASH && init_num != 0)
		buffer[i--] = '0';

	i++;

	return (write_unsgnd(0, i, buffer, flags, width, precision, size));
}

/* printing number in hexa */
/**
 * print_hexadecimal - printss number
 * @types: arguments
 * @buffer: array
 * @flags: flags
 * @width: width
 * @precision: precision
 * @size: the size
 * Return: number
 */
int print_hexadecimal(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	return (print_hexa(types, "0123456789abcdef", buffer,
		flags, 'x', width, precision, size));
}

/* printing in hexa but unsigned */
/**
 * print_hexa_upper - prints number
 * @types: arguments
 * @buffer: array
 * @flags: flags
 * @width: width
 * @precision: precision
 * @size: size
 * Return: number
 */
int print_hexa_upper(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	return (print_hexa(types, "0123456789ABCDEF", buffer,
		flags, 'X', width, precision, size));
}

/* printing lower and upper */
/**
 * print_hexa - printing in lower and upper
 * @types: the argumens
 * @map_to: the array
 * @buffer: buffer
 * @flags:  flags
 * @flag_ch: calc of flags
 * @width: the width
 * @precision: precisio
 * @size: the size
 * @size: the size
 * Return: chars
 */
int print_hexa(va_list types, char map_to[], char buffer[],
	int flags, char flag_ch, int width, int precision, int size)
{
	int i = BUFF_SIZE - 2;
	unsigned long int num = va_arg(types, unsigned long int);
	unsigned long int init_num = num;

	UNUSED(width);

	num = convert_size_unsgnd(num, size);

	if (num == 0)
		buffer[i--] = '0';

	buffer[BUFF_SIZE - 1] = '\0';

	while (num > 0)
	{
		buffer[i--] = map_to[num % 16];
		num /= 16;
	}

	if (flags & F_HASH && init_num != 0)
	{
		buffer[i--] = flag_ch;
		buffer[i--] = '0';
	}

	i++;

	return (write_unsgnd(0, i, buffer, flags, width, precision, size));
}

