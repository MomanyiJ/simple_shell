#ifndef _SHELL_H_
#define _SHELL_H_

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <limits.h>
#include <signal.h>


/**
 * struct variables - variables
 * @av: command line arguments
 * @buffer: buffer of command
 * @env: environment variables
 * sum: total of commands entered
 * @argv: arguments at opening of shell
 * @status: exit status
 */
typedef struct variables
{
	char **av;
	char *buffer;
	char **env;
	size_t sum;
	char **argv;
	int status;
	char **commands;
} vars_t;

/**
 * struct builtins - struct for the builtin functions
 * @name: name of builtin command
 * @f: function for corresponding builtin
 */
typedef struct builtins
{
	char *name;
	void (*f)(vars_t *);
} builtins_t;

char **create_env(char **env);
void free_env(char **env);

ssize_t _puts(char *str);
char *_strdup(char *strtk_dup);
int _strcmpr(char *strcmp1, char *strcmp2);
char *_strcat(char *strc1, char *strc2);
unsigned int _strlen(char *str);

char **tokenize(char *buffer, char *delimiter);
char **_realloc(char **ptr, size_t *size);
char *_strtok(char *str, const char *delim);

void (*check_for_builtins(vars_t *vars))(vars_t *vars);
void new_exit(vars_t *vars);
void _env(vars_t *vars);

int _atoi(char *str);

void check_path(vars_t *vars);
int path_execute(char *command, vars_t *vars);
char *find_path(char **env);
int _execute(vars_t *vars);
int check_file_status(char *str);

void print_error(vars_t *vars, char *msg);
void _puts2(char *str);
char *_unitoa(unsigned int sum);

#endif /* _SHELL_H_ */

