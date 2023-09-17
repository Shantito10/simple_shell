#include "main.h"
#include <stdio.h>
#include <unistd.h>

void launch_command(char **argv)
{
	if (argv[0] != NULL)
	{
		if (execve(argv[0], argv, NULL) == -1)
		{
			perror("hsh");
		}
	}
}
