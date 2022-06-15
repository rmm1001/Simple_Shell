#include "shell.h"

/**
 * _putchar - write the input character to stdout
 * @c: Input character
 *
 * Return: 1 if successful, otherwise -1.
 */

int _putchar(char c)
{
	return (write(STDOUT_FILENO, &c, 1));
}

/**
 * _puts - prints a string
 * @str: pointer to the string to be printed
 *
 * Return: Nothing
 */

void _puts(char *str)
{
	int i = 0;

	while (str[i])
	{
		_putchar(str[i]);
		i++;
	}
}
