#include "shell.h"

/**
 * main - displays the command window prompt
 * @argc: integer input
 * @argv: pointer to pointer of char
 * *
 * Return: 0 on success.
 */

int main(int argc, char *argv[])
{
	char **token;
	char *line;
	int status;
	struct stat s;

	(void)argc;

	signal(SIGINT, ctrl_c);
	if (fstat(0, &s) == -1)
		perror("fstat");
	status = 1;
	do {
		_prompt();
		line = read_line();
		if (_strcmp(line, "\n") == 0)
		{
			token = NULL;
			free(line);
			continue;
		}
		get_history(line);
		token = str_to_token(line);
		if (token[0] == NULL)
		{
			free(token);
			free(line);
			continue;
		}

		if (_strcmp(token[0], "exit") == 0)
			hsh_exit(token, line);
		else
			status = _execute(token, line, argv[0]);

		free(line);
		free(token);
	} while (status == 1);
	return (status);
}
