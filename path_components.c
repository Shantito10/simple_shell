#include "main.h"

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
			values = strtok(NULL, "=");
			free(current_env_copy);
			return (values);
		}

		free(current_env_copy);
		env_index++;
	}

	return (NULL);
}

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

char *_which(char *command_name)
{
	char *pathenv = _getenv("PATH");
	char **path_vector = path_tokenizer(pathenv);
	char *full_path = NULL;
	char *current_path = NULL;
	int index, last_char_idx;
	size_t full_path_size;
	struct stat st;

	for (index = 0; path_vector[index] != NULL; index++)
	{
		current_path = path_vector[index];
		last_char_idx = _strlen(current_path) - 1;
		full_path_size = _strlen(current_path) + _strlen(command_name) + 2;

		full_path = malloc(full_path_size);
		if (!full_path)
		{
			free(path_vector);
			return (NULL);
		}

		_strcpy(full_path, current_path);
		if (current_path[last_char_idx] != '/')
			_strcat(full_path, "/");
		_strcat(full_path, command_name);

		if (stat(full_path, &st) == 0)
		{
			free(path_vector);
			return (full_path);
		}
		free(full_path);
	}

	free(path_vector);
	return (NULL);
}
