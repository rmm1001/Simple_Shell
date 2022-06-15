#include "shell.h"

/**
 * _free - frees a two dimensional string
 * @args: pointer to a string
 *
 * Return: Nothing
 */

void _free(char **args)
{
	int i = 0;

	for (i = 0; args[i]; i++)
	{
		free(args[i]);
	}
	free(args);
}

/**
 * read_line - reads input/command from stdin
 *
 * Return: pointer to string with command
 */

char *read_line(void)
{
	char *command = NULL;
	int var = 0;
	size_t len = 0;

	var = getline(&command, &len, stdin);
	if (var == EOF)
	{
		free(command);
		exit(0);
	}
	if (command == NULL)
	{
		write(STDOUT_FILENO, "\n", 1);
		free(command);
		exit(-1);
	}
	return (command);
}
