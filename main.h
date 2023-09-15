#ifndef MAIN_H
#define MAIN_H

#define DELIM " \t\r\n\a"

void shell_loop(void);
char *shell_read_line(void);
char **argument_parser(char *line);
unsigned int _isdelim(char c);
int argument_counter(char *line);

#endif /* MAIN_H */
