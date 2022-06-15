#include "shell.h"

/**
 * _prompt - displays prompt before user command
 *
 * Return: Nothing.
 */

void _prompt(void)
{
	if (isatty(STDIN_FILENO))
		_puts("#cisfun$ ");
}

/**
 * ctrl_c - quits the command that is running
 * @num: SIGINT variable
 *
 * Return: Nothing
 */

void ctrl_c(int num)
{
	(void)num;
	signal(SIGINT, ctrl_c);
	write(STDIN_FILENO, "\n#cisfun$ ", 11);
}

/**
 * hsh_exit - exits the shell
 * @args: command passed
 * @line: string to free
 *
 * Return: Nothing.
 */

void hsh_exit(char **args, char *line)
{
	int status = 0;

	if (args[1] != NULL)
	{
		status = atoi(args[1]);
		if (status >= 0)
		{
			free(line);
			free(args);
			exit(status);
		}
		printf("Exit: illegal status: %s\n", args[1]);
	}
	else
	{
		free(line);
		free(args);
		exit(0);
	}
}
