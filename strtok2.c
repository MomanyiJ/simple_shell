#include "shell.h"


/**
 * _tokenize - tokenizes a buffer with a delimiter
 * @buffer: buffer to tokenize
 * @delimiter: delimiter to tokenize along
 *
 * Return: pointer to an array of pointers to the tokens
 */
char **tokenize(char *buffer, char *delimiter)
{
	char **tokens = NULL;
	size_t i = 0, total = 10;

	if (buffer == NULL)
		return (NULL);
	tokens = malloc(sizeof(char *) * total);
	if (tokens == NULL)
	{
		perror("Fatal Error");
		return (NULL);
	}
	while ((tokens[i] = _strtok(buffer, delimiter)) != NULL)
	{
		i++;
		if (i == total)
		{
			tokens = _realloc(tokens, &total);
			if (tokens == NULL)
			{
				perror("Fatal Error");
				return (NULL);
			}
		}
		buffer = NULL;
	}
	return (tokens);
}

/**
 * _realloc - reallocates a pointer to double the space
 * @ptr: pointer to the old array
 * @size: pointer to number of elements in the old array
 *
 * Return: pointer to the new array
 */
char **_realloc(char **ptr, size_t *size)
{
	char **new_ptr;
	size_t i;

	new_ptr = malloc(sizeof(char *) * ((*size) + 10));
	if (new_ptr == NULL)
	{
		free(ptr);
		return (NULL);
	}
	for (i = 0; i < (*size); i++)
	{
		new_ptr[i] = ptr[i];
	}
	*size += 10;
	free(ptr);
	return (new_ptr);
}
