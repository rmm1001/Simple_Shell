#include "shell.h"

/**
 * get_history - fills file with user commands
 * @input: input command
 *
 * Return: 0 on success, otherwise -1.
 */

int get_history(char *input)
{
	ssize_t w, fd;
	int i = 0;
	char *filename = "/.hsh_history";
	char *directory = get_env("HOME");
	char *filepath = malloc(_strlen(directory) + _strlen(filename) + 1);

	if (!filepath)
	{
		perror("malloc error->get_history");
		free(directory);
		return (-1);
	}
	_strcpy(filepath, directory);
	_strcpy(filepath, filename);

	fd = open(filepath, O_CREAT | O_RDWR | O_APPEND, 0600);
	if (fd < 0)
		return (-1);
	if (input)
	{
		while (input[i])
			i++;
		w = write(fd, input, i);
		if (w < 0)
			return (-1);
	}
	free(filepath);
	free(directory);
	return (1);
}

/**
 * display_history - displays history of user input command
 *
 * Return: 0 on success, otherwise -1.
 */

int display_history(void)
{
	FILE *fp;
	int count = 0;
	char *filename = "/.hsh_history";
	char *directory = get_env("HOME");
	char *filepath = malloc(_strlen(filename) + _strlen(directory) + 1);
	char *line = NULL;
	size_t i;

	if (!filepath)
	{
		perror("malloc error->display_history");
		free(directory);
		return (-1);
	}
	_strcpy(filepath, directory);
	_strcpy(filepath, filename);

	fp = fopen(filepath, "r");
	if (fp == NULL)
		return (-1);
	while (getline(&line, &i, fp) != -1)
	{
		count++;
		printf("%d %s", count, line);
	}
	if (line != NULL)
		free(line);
	fclose(fp);
	free(filepath);
	free(directory);
	return (0);
}
