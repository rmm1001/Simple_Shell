#include "shell.h"

/**
 * _occurence - get the # of times a string occures
 * @s: string to be checked
 *
 * Return: integer
 */

unsigned int _occurence(char *s)
{
	int i, count = 0;

	for (i = 0; s[i] != '\0'; i++)
	{
		if (s[i] == ' ' || s[i] == '\t' || s[i] == '\n')
			count++;
	}
	return (count);
}

/**
 * file_status - checks if a file exists
 * @filename: name of the file to check
 *
 * Return: 0 if it exist, otherwise -1.
 */

int file_status(char *filename)
{
	struct stat s;

	if (stat(filename, &s) == -1)
		return (-1);
	return (0);
}

/**
 * str_to_token - splits sentence into seperate words
 * @str: the string to split
 *
 * Return: tokens/words
 */

char **str_to_token(char *str)
{
	int i = 0;
	char **tks = malloc(sizeof(char *) * (_occurence(str) + 1));
	char *token;
	const char separator[] = " \t\n";

	if (!tks)
	{
		fprintf(stderr, "sh: allocation error\n");
		exit(1);
	}
	token = strtok(str, separator);
	while (token != NULL)
	{
		tks[i] = token;
		token = strtok(NULL, separator);
		i++;
	}
	tks[i] = NULL;
	return (tks);
}

/**
 * _execute - execute given inout file
 * @token: splits command from stdin to tokens
 * @line: line from stdin to free
 * @args: command
 *
 * Return: 1 on success, otherwise -1.
 */


int _execute(char **token, char *line, char *args)
{
	char *err1, *err2, *err3;
	pid_t cpid;
	int status;
	struct stat s;

	if (_parse(token) == 0 || *token == NULL)
		return (1);
	cpid = fork();
	if (cpid < 0)
	{
		perror("Error: for->-1");
		return (EXIT_FAILURE);
	}
	if (cpid == 0)
	{
		if (stat(*token, &s) != 0)
			get_path(token);
		if (execve(token[0], token, NULL) == -1)
		{
			err1 = strcat(*token, ": No such file or DIrectory\n");
			err2 = strcat(args, ":");
			err3 = strcat(err2, err1);
			write(STDERR_FILENO, err3, _strlen(err3));
			free(line);
			free(token);
			exit(EXIT_FAILURE);
		}
		return (EXIT_SUCCESS);
	}
	wait(&status);
	return (1);
}
