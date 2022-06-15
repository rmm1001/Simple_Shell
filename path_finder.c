#include "shell.h"

/**
 * get_env - gets the environment
 * @path: passed argument
 *
 * Return: pointer to a string
 */

char *get_env(char *path)
{
	char *envc;
	int i = 0, len1, len2;

	while (environ[i])
	{
		len1 = _strlen(path);
		if (strstr(environ[i], path))
		{
			if (environ[i][len1] == '=')
			{
				len2 = _strlen(environ[i]) - _strlen(path);
				envc = malloc(sizeof(char) * len2);
				if (envc == NULL)
				{
					perror("Error: Insufficient memor");
					exit(1);
				}
				_strcpy(envc, environ[i] + (len1 + 1));
				return (envc);
			}
		}
		i++;
	}
	return (NULL);
}

/**
 * get_path - gets the path of a command
 * @args: pointer to pointer to strings
 *
 * Return: int
 */

int get_path(char **args)
{
	char *_cmd, *path, *token;
	struct stat s;

	path = get_env("PATH");
	token = strtok(path, ":");

	while (token != NULL)
	{
		_cmd = cmd_build(*args, token);
		if (stat(_cmd, &s) == 0)
		{
			*args = _strdup(_cmd);
			free(_cmd);
			free(path);
			return (0);
		}
		free(_cmd);
		token = strtok(NULL, ":");
	}
	free(path);
	return (1);
}

/**
 * cmd_build - gets cmd path
 * @token: cmd parse
 * @dir: current working directory
 *
 * Return: pointer to the string of wd
 */

char *cmd_build(char *token, char *dir)
{
	size_t len;
	char *path;

	len = _strlen(token) + _strlen(dir) + 2;
	path = malloc(sizeof(char) * len);
	if (path == NULL)
	{
		perror("Error: malloc->buildcmd\n");
		return (NULL);
	}
	memset(path, 0, len);

	path = _strcat(path, dir);
	path = _strcat(path, "/");
	path = _strcat(path, token);
	return (path);
}
