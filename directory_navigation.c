#include "shell.h"

/**
 * get_cwd - obtains the current working directory
 *
 * Return: string shwing the current working directory
 */

char *get_cwd(void)
{
	size_t len = PATH_MAX;
	char *cwd;

	cwd = malloc(sizeof(char) * len);
	if (cwd == NULL)
	{
		perror("Error: Memory allocation cwd\n");
		return (NULL);
	}
	if (getcwd(cwd, len) == NULL)
	{
		free(cwd);
		perror("Error: getcwd->NULL\n");
		return (NULL);
	}
	return (cwd);
}

/**
 * cd_prev - navigated to previous dir when cd - is the input command
 *
 * Return: Always 0.
 */

int cd_prev(void)
{
	char *back, *cwd;

	cwd = get_cwd();

	back = getenv("OLDPWD");
	chdir(back);
	back = NULL;

	set_env("OLDPWD", cwd);
	cwd = NULL;

	cwd = get_cwd();
	set_env("PWD", cwd);
	free(cwd);

	return (0);
}

/**
 * cd_home - navigate to home when only cd is input
 *
 * Return: Always 0.
 */

int cd_home(void)
{
	char *home, *cwd;

	cwd = get_cwd();
	set_env("OLDPWD", cwd);
	free(cwd);

	home = getenv("HOME");
	chdir("home");
	free(home);

	cwd = get_cwd();
	set_env("PWD", cwd);
	free(cwd);

	return (0);
}

/**
 * _cd - changes the current working directory
 * @args: command to parse from read_line
 *
 * Return: Always 0.
 */

int _cd(char **args)
{
	char *cwd;

	if (args[1] != NULL)
	{
		if (strncmp(args[1], "-", 1) == 0)
		{
			cd_prev();
		}
		else
		{
			cwd = get_cwd();
			set_env("OLDPWD", cwd);
			free(cwd);
			if (chdir(args[1]) == -1)
			{
				perror("Error: chdir\n");
			}
			cwd = get_cwd();
			set_env("PWD", cwd);
			free(cwd);
		}
	}
	else
		cd_home();
	return (0);
}
