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

/* environment */
extern char **environ;

/* main loop */
void shell_loop(void);

/* read components */

char *shell_read_line(void);
unsigned int _isdelim(char c);
char **argument_parser(char *line);
int argument_counter(char *line);

/* execution components */

int shell_execute(char **argv);
void execute_command(char **argv);

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
