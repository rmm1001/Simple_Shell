#include "shell.h"

/**
 * _environ - prints environment
 *
 * Return: 1 if successful
 */

int _environ(void)
{
	int i = 0;

	for (i = 0; environ[i]; i++)
	{
		printf("%s\n", environ[i]);
	}
	return (1);
}

/**
 * var_build - build environment variable from the name and value
 * @name: variable name
 * @value: variable value
 *
 * Return: string with environment variables
 */

char *var_build(char *name, char *value)
{
	char *_new;
	size_t len;

	len = _strlen(name) + _strlen(value) + 2;
	_new = malloc(sizeof(char) * len);

	if (_new == NULL)
	{
		perror("Error: Insufficient memory\n");
		return (NULL);
	}
	memset(_new, 0, len);
	_new = _strcat(_new, name);
	_new = _strcat(_new, "=");
	_new = _strcat(_new, value);
	return (_new);
}

/**
 * set_env - sets up  the environment
 * @name: Name of input variable
 * @value: value of the input variable
 *
 * Return: 0 on success, otherwise -1.
 */

int set_env(char *name, char *value)
{
	int i = 0;
	char *_new;
	size_t len = _strlen(name);

	while (environ[i])
	{
		if (strncmp(environ[i], name, len) == 0)
		{
			_new = var_build(name, value);
			environ[i] = NULL;
			environ[i] = _strdup(_new);
			free(environ[i]);
			environ[i] = _strdup(_new);
			free(_new);
			return (0);
		}
		i++;
	}
	_new = var_build(name, value);
	free(environ[i]);
	environ[i] = _strdup(_new);
	i++;
	environ[i] = NULL;
	_new = NULL;
	return (0);
}

/**
 * unset_env - removes environment variable
 * @name: variable name
 *
 * Return: 0 if successful, otherwise -1.
 */

int unset_env(char *name)
{
	int i = 0;
	char **_env;
	size_t len;

	len = _strlen(name);
	while (environ[i])
	{
		if (strncmp(environ[i], name, len) == 0)
		{
			_env = environ;
			free(_env[0]);
			do {
				_env[0] = _env[1];
				_env++;
			} while (*_env);
		}
		i++;
	}
	return (0);
}
