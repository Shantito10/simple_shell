#include "main.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * _setenv - this function modifies the environment variables
 * by adding a new environment variable or modifying an existing one
 *
 * @name: name of the variable to add or modify
 * @value: value of the variable to add or modify
 * @overwrite: integer value representing
 * whether to overwrite an existing variable or not
 *
 * Return: 0 for success, -1 for failure
 */

int _setenv(char *name, char *value, int overwrite)
{
	int env_length = get_env_length();
	int env_position = 0;
	char **modified_environ;
	char *new_variable = env_join(name, value);
	char *temp_env;

	if (_getenv(name))
	{
		if (overwrite)
		{
			while (environ[env_position])
			{
				temp_env = _strdup(environ[env_position]);
				if (!_strcmp(strtok(temp_env, "="), name))
				{
					environ[env_position] = new_variable;
					free(temp_env);
					return (0);
				}
				free(temp_env);
				env_position++;
			}
		}
		else
			return (0);
	}
	else
	{
		modified_environ = (char **)malloc(sizeof(char *) * (env_length + 2));
		if (!modified_environ)
			return (-1);
		for (env_position = 0; env_position < env_length; env_position++)
			modified_environ[env_position] = _strdup(environ[env_position]);
		modified_environ[env_position] = _strdup(new_variable);
		modified_environ[++env_position] = NULL;
		environ = modified_environ;
		return (0);
	}
	return (-1);
}

/**
 * _unsetenv - a function that deletes
 * an environment variable from the environment
 * @name: the name of the variable to delete
 *
 * return: 0 on success, -1 failure
 */

int _unsetenv(char *name)
{
	int env_length = (get_env_length() - 1);
	int env_position = 0;
	int new_env_position = 0;
	char *env_var;
	char **modified_environ;

	if (_getenv(name))
	{
		modified_environ = (char **)malloc(sizeof(char *) * (env_length));
		if (!modified_environ)
			return (-1);

		for (env_position = 0; env_position < env_length; env_position++)
		{
			env_var = _strdup(environ[env_position]);
			if (_strcmp(strtok(env_var, "="), name))
			{
				modified_environ[new_env_position] = _strdup(environ[env_position]);
				new_env_position++;
			}

			free(env_var);
		}
		modified_environ[new_env_position] = NULL;
		environ = modified_environ;
		return (0);
	}
	else
	{
		return (0);
	}

}

int main(void)
{
	exec_status_t res;
	char **argv = NULL;

	printf("\n\tOLD ENV\n\n");
	res = shell_env(argv);

	_setenv("SERGIO", "ramosita", 0);

	printf("\n\tNEW ENV\n\n");
	res = shell_env(argv);

	_setenv("SERGIO", "aguesito", 1);

	printf("\n\tMOD ENV\n\n");
	res = shell_env(argv);

	_unsetenv("SERGIO");
	_unsetenv("LOGNAME");
	printf("\n\tDELETE ENV\n\n");
	res = shell_env(argv);

	return (0);
}
