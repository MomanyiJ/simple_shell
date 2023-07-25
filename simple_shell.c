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
			array[i++] = token;
			token = strtok(NULL, " \n");

		}
		array[i] = NULL;
		/** testing whether the string has been separated
		*for (i=0; array[i] != NULL; i++)
		*{
		*	printf("%s \n", array[i]);
		*}
		*/
		
		 

		/* calling path_finder function */
		path_finder(array);
	}
	return (0);
}


void path_finder( char **cmd)
{
	int i = 0;
	char *path, *token, *p_c, *dp;;
	int j, k = 0, status;
	struct stat buf;
	

	/* loop through the environ array */
	for (i = 0; environ[i] !=NULL; i++)
	{
		/*printf("%d %s \n", i,environ[i]);*/

		/* compare PATH and environ[i] first four characters*/

		if (strncmp("PATH", environ[i], 4) == 0)
		{
			path = malloc(sizeof(char) * (strlen(environ[i]) - 4));
			
			for (j = 5; environ[i][j] !='\0'; k++)
			{
				path[k] = environ[i][j];
				printf("%c", path[k]);
				j++;
			}

			
			/* to separate the path dirs by : and . */
			token = strtok(path, ":");
			p_c = malloc(szeof(char) * 1024);

			while (token != NULL)


			
			while (token != NULL)
			{
				dp = strdup(token);
				p_c = strcat(dp. "/");
				p_c =strcat(p_c, cmd[0]);
				
				if(stat(p_c, &buf) ==0)
				{
					if(fork() !=0)
						wait(&status);
					else
						execve(p_c, cmd, environ);
					break;

				}
				token=strtok(NULL, ":");
			}
		}

	}
}
