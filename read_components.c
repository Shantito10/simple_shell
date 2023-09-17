#include "main.h"

char *shell_read_line(void)
{
	char *line = NULL;
	size_t line_buffer_size = 0;

	if (getline(&line, &line_buffer_size, stdin) == -1)
	{
		return (NULL);
	}

	return (line);
}

unsigned int _isdelim(char c)
{
	int delim_index = 0;
	char *delimiters = DELIM;

	while (*(delimiters + delim_index) != '\0')
	{
		if (*(delimiters + delim_index) == c)
		{
			return (1);
		}

		delim_index++;
	}

	return (0);
}

int argument_counter(char *line)
{
	int i = 0;
	int argc = 0;
	char current_char;
	char next_char;

	while (*(line + i) != '\0')
	{
		current_char = *(line + i);
		next_char = *(line + (i + 1));

		if ((!_isdelim(current_char))
				&& (_isdelim(next_char) || next_char == '\0'))
		{
			argc++;
		}
		i++;
	}

	return (argc);
}

char **argument_parser(char *line)
{
	int argc = argument_counter(line);
	int position = 0;
	char **argv = malloc(sizeof(char *) * (argc + 1));
	char *arg = NULL;

	if (!argv)
	{
		return (NULL);
	}

	arg = strtok(line, DELIM);

	while (arg != NULL)
	{
		argv[position] = arg;
		position++;

		arg = strtok(NULL, DELIM);
	}

	argv[position] = NULL;
	return (argv);
}
