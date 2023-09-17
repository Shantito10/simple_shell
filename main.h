#ifndef MAIN_H
#define MAIN_H

#define DELIM " \t\r\n\a"

#include <string.h>
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void shell_loop(void);

char *shell_read_line(void);
unsigned int _isdelim(char c);
char **argument_parser(char *line);
int argument_counter(char *line);

void shell_execute(char **argv);
void execute_command(char **argv);

#endif /* MAIN_H */
