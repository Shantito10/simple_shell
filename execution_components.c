#include "main.h"
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

void shell_execute(char **argv)
{
	if (argv[0] != NULL)
	{
		char *path = _which(argv[0]);

		if (path)
		{
			argv[0] = path;
		}
		execute_command(argv);
		if (path)
		{
			free(path);
		}
	}
}

void execute_command(char **argv)
{
	pid_t child_pid;
	int status;

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
}
