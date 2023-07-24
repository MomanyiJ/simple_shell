#include "main.h"
/**
 * main - execve
 *
 * @argc: number of arguments
 * @argv: argument vectors
 * Return: Always 0.
 */

int main()
{
	char *line, **array, *token;
		size_t len = 0;
	int i;
	while (1)
	{
		/* display prompt to use using write since printf isnt allowed*/
		write(1, "$ ", 2);
		/* read input and assign it to line */
		getline(&line, &len, stdin);

		/* separatint the string */
		token = strtok(line, " \n");
		if (token == NULL)
			continue;

		/* declare size of array */
		array = malloc(sizeof(char *) * 1024);

		i = 0;
		while (token)
		{
			aray[i++] = token;
			token = strtok(NULL, " \n");

		}
		array[i] = NULL;

		for (i=0; array[i] != NULL; i++)
		{
			printf("%s \n", array[i]);
		}


	}
	return (0);
}
