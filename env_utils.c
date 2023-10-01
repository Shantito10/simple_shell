#include "main.h"
#include <stdlib.h>

/**
 * get_env_length - this function gets the number of environment variables
 *
 * Return: Number of environment variables
 */

int get_env_length(void)
{
	int length = 0;

	if (environ)
	{
		while (environ[length])
		{
			length++;
		}

		return (length);
	}

	return (0);
}

/**
 * free_environ - this function frees the environ variable
 * @env: an array of environment variable strings
 *
 * Return: nothing
 */

void free_environ(char **env)
{
	int index = 0;

	if (env)
	{
		while (env[index])
		{
			free(env[index]);
			index++;
		}

		free(env);
	}
}

/**
 * env_join - this function joins a given name string
 * and value string into an environment variable string
 * for the environ variable
 *
 * @name: name of the environment variable
 * @value: value of the environment variable
 *
 * Return: joined string of the environment variable
 */

char *env_join(char *name, char *value)
{
	char *full_env_var = NULL;
	size_t env_var_size = 0;

	if (name && value)
	{
		env_var_size = _strlen(name) + _strlen(value) + 2;
		full_env_var = (char *)malloc(sizeof(char) * env_var_size);

		if (!full_env_var)
			return (NULL);

		_strcpy(full_env_var, name);
		_strcat(full_env_var, "=");
		_strcat(full_env_var, value);

		return (full_env_var);
	}

	return (NULL);
}

