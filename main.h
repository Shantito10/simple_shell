#ifndef MAIN_H
#define MAIN_H

#define DELIM " \t\r\n\a"
#define PATH_DELIM ":"

#include <string.h>
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>

/* environment */
extern char **environ;

/* main loop */
void shell_loop(void);

/* read components */

char *shell_read_line(void);
unsigned int _isdelim(char c);
char **argument_parser(char *line);
int argument_counter(char *line);

/**
 * struct exec_status - function
 * @_isexit: name of file
 * @status: check status
 * Return: 0
 */
typedef struct exec_status
{
	unsigned int _isexit;
	int status;
} exec_status_t;

/* execution components */
exec_status_t shell_execute(char **argv);
exec_status_t execute_command(char **argv);

/* built-in struct */
/**
 * struct builtins - function
 * @command: command name
 * @builtin_func: builtin function
 * Return: 0
 */
typedef struct builtins
{
	char *command;
	exec_status_t (*builtin_func)(char **);
} builtins_t;

exec_status_t (*get_builtin(char *command_name))(char **argv);

/* built-ins */
exec_status_t shell_exit(char **argv);
exec_status_t shell_env(char **argv);

/* path components */
char *_getenv(char *env_name);
unsigned int _ispathdelim(const char c);
int path_token_counter(char *path_string);
char **path_tokenizer(char *path_string);
char *_which(char *command_name);
char *_path_join(char *path, char *command_name);

/* utilities */
int _strlen(char *str);
char *_strcpy(char *dest, char *src);
char *_strdup(char *str);
int _strcmp(char *s1, char *s2);
char *_strcat(char *dest, char *src);
int _isapath(char *str);

#endif /* MAIN_H */
