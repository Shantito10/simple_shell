#include "main.h"

/**
 * _getenv - fuction entry
 * @env_name: file name
 *
 * Return: 0, or NULL
 */
char *_getenv(char *env_name)
{
	int env_index = 0;
	char *current_env = NULL;
	char *current_env_copy = NULL;
	char *name = NULL;
	char *values = NULL;

	while (environ[env_index])
	{
		current_env = environ[env_index];
		current_env_copy = _strdup(current_env);
		name = strtok(current_env_copy, "=");
		if (!_strcmp(name, env_name))
		{
			values = _strdup(strtok(NULL, "="));

			free(current_env_copy);
			return (values);
		}

		free(current_env_copy);
		env_index++;
	}

	return (NULL);
}

/**
 * _ispathdelim - fuction path delim
 * @c: argument count
 * Return: 0
 */
unsigned int _ispathdelim(const char c)
{
	int delim_index = 0;
	char *delimiters = PATH_DELIM;

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

/**
 * path_token_counter - function entry for string path
 * @path_string: char to path_string
 * Return: 0, or nothing
 */
int path_token_counter(char *path_string)
{
	int i = 0;
	int token_count = 0;
	char current_char;
	char next_char;


	while (*(path_string + i) != '\0')
	{
		current_char = *(path_string + i);
		next_char = *(path_string + (i + 1));

		if ((!_ispathdelim(current_char))
				&& (_ispathdelim(next_char) || next_char == '\0'))
		{
			token_count++;
		}
		i++;
	}

	return (token_count);
}

/**
 * path_tokenizer - fuction for string count
 * @path_string: string
 * Return: 0, if not NULL
 */
char **path_tokenizer(char *path_string)
{
	if (path_string)
	{
		int token_count = path_token_counter(path_string);
		int position = 0;
		char **token_vector = malloc(sizeof(char *) * (token_count + 1));
		char *token = NULL;

		if (!token_vector)
		{
			return (NULL);
		}

		token = strtok(path_string, PATH_DELIM);

		while (token != NULL)
		{
			token_vector[position] = token;
			position++;

			token = strtok(NULL, PATH_DELIM);
		}

		token_vector[position] = NULL;
		return (token_vector);
	}
	else
	{
		return (NULL);
	}
}

/**
 * _which - fuction for command name
 * @command_name: argument count
 * Return: 0, if not NULL
 */
char *_which(char *command_name)
{
	char *pathenv = NULL;
	char **path_vector = NULL;
	char *full_path = NULL;
	int index;
	struct stat st;

	if (_isapath(command_name))
	{
		if (stat(command_name, &st) == 0)
			return (_strdup(command_name));
	}

	pathenv = _getenv("PATH");
	path_vector = path_tokenizer(pathenv);

	for (index = 0; path_vector[index] != NULL; index++)
	{
		full_path = _path_join(path_vector[index], command_name);

		if (!full_path)
		{
			free(pathenv);
			free(path_vector);
			return (NULL);
		}

		if (stat(full_path, &st) == 0)
		{
			free(pathenv);
			free(path_vector);
			return (full_path);
		}
		free(full_path);
	}

	free(pathenv);
	free(path_vector);
	return (NULL);
}
