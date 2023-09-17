#include "main.h"
#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

void shell_execute(char **argv)
{
	if (argv[0] != NULL)
	{
		execute_command(argv);
	}
}

void execute_command(char **argv)
{
	pid_t child_pid;
	int status;

	child_pid = fork();

	if (child_pid == -1)
	{
		perror("hsh");
	}
	else if (child_pid == 0)
	{
		/* Child process */
		if (execve(argv[0], argv, NULL) == -1)
		{
			perror("lsh");
		}
	}
	else
	{
		wait(&status);
	}
}
