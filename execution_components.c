#include "main.h"
#include <stdlib.h>

/**
 * shell_execute - function for shell execution
 * @argv: argument vector
 * Return: no return
 */
int shell_execute(char **argv)
{
	if (argv[0] == NULL)
	{
		return (0);
	}

	if (get_builtin(argv[0]))
	{
		return (get_builtin(argv[0])(argv));
	}

	return (execute_command(argv));
}

/**
 * execute_command - fuction for command execution
 * @argv: argument vector
 *
 * Return: return nothing
 */
int execute_command(char **argv)
{
	pid_t child_pid;
	int status;
	char *path;
	char *command = argv[0];

	path = _which(command);

	if (path)
	{
		argv[0] = path;

		child_pid = fork();

		if (child_pid == -1)
		{
			perror("./hsh");
		}
		else if (child_pid == 0)
		{
			/* Child process */
			if (execve(argv[0], argv, environ) == -1)
			{
				perror("./hsh");
			}
		}
		else
		{
			wait(&status);
		}
		free(path);
		return (WEXITSTATUS(status));
	}
	else
	{
		write(STDERR_FILENO, "./hsh: 1: ", 10);
		write(STDERR_FILENO, argv[0], _strlen(argv[0]));
		write(STDERR_FILENO, ": not found\n", 12);

		return (127);
	}
}

int (*get_builtin(char *command_name))(char **argv)
{
	builtins_t commands[] = {
		{"exit", shell_exit},
		{"env", shell_env},
		{NULL, NULL}
	};
	int i = 0;

	while (commands[i].command != NULL)
	{
		if (!_strcmp(commands[i].command, command_name))
		{
			return (commands[i].builtin_func);
		}

		i++;
	}

	return (NULL);
}
