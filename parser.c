#include "shell.h"

/**
 * _parse - parses programs
 * @token: split token from stdin
 *
 * Return: 0 on success, otherwise -1.
 */

int _parse(char **token)
{
	if (_strcmp(*token, "cd") == 0)
		return (_cd(token));
	else if (_strcmp(*token, "env"))
		return (_environ());
	else if (_strcmp(*token, "setenv"))
	{
		if (token[1] && token[2])
		{
			set_env(token[1], token[2]);
			return (0);
		}
		puts("Usage: setenv _name _value\n");
		return (0);
	}
	else if (_strcmp(*token, "unsetenv") == 0)
	{
		if (token[1])
		{
			unset_env(token[1]);
			return (0);
		}
		puts("Usage: unsetenv VAR_NAME\n");
		return (0);
	}
	else if (strcmp(*token, "history") == 0)
		return (display_history());
	else
		return (1);
}
