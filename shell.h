#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include <unistd.h>
#include <signal.h>
#include <errno.h>
#include <fcntl.h>
#include <limits.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>

/*#define PATH_MAX 1024 */

extern char **environ;

/* setting up the environment */
int _environ(void);
int set_env(char *name, char *value);
char *var_build(char *name, char *value);
int unset_env(char *name);

/* functions for dealing with strings*/
int _putchar(char c);
void _puts(char *str);
int _strlen(char *str);
char *_strdup(char *str);
char *_strcat(char *dest, char *src);
int _strcmp(char *s1, char *s2);
char *_strcpy(char *dest, char *src);

/* Changing directory function */
int _cd(char **args);
int cd_home(void);
int cd_prev(void);
char *get_cwd(void);

/* Executing functions */
int _execute(char **token, char *line, char *args);
int file_status(char *filename);
unsigned int _occurence(char *s);
char **str_to_token(char *str);

/* Dealiing with path */
char *get_env(char *path);
int get_path(char **args);
char *cmd_build(char *token, char *dir_value);

/* Dispalying history */
int get_history(char *input);
int display_history(void);

/* shell help */
int _help(char **args);

/* reallocating funtion */
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size);

/* reading lines */
char *read_line(void);
char *read_line_again(void);
void _free(char **args);

/* Exiting the shell */
void _prompt(void);
void ctrl_c(int num);
void hsh_exit(char **args, char *line);
char *ignore_space(char *str);

int main(int argc, char *argv[]);
int _parse(char **);


#endif
