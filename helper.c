#include "shell.h"

/**
 * print_error - prints error messages to standard error
 * @vars: pointer to struct of variables
 * @msg: message to print
 *
 * Return: void
 */
void print_error(vars_t *vars, char *msg)
{
	char *sum;

	_puts2(vars->argv[0]);
	_puts2(": ");
	sum = _unitoa(vars->sum);
	_puts2(sum);
	free(sum);
	_puts2(": ");
	_puts2(vars->av[0]);
	if (msg)
	{
		_puts2(msg);
	}
	else
		perror("");
}

/**
 * _puts2 - prints a string to standard error
 * @str: string to print
 *
 * Return: void
 */
void _puts2(char *str)
{
	ssize_t num, len;

	num = _strlen(str);
	len = write(STDERR_FILENO, str, num);
	if (len != num)
	{
		perror("Fatal Error");
		exit(1);
	}

}

/**
 * _unitoa - converts an unsigned int to a string
 * @sum: unsigned int to convert
 *
 * Return: pointer to the converted string
 */
char *_unitoa(unsigned int sum)
{
	char *numstr;
	unsigned int xy, digits;

	xy = sum;
	for (digits = 0; xy != 0; digits++)
		xy /= 10;
	numstr = malloc(sizeof(char) * (digits + 1));
	if (numstr == NULL)
	{
		perror("Fatal Error1");
		exit(127);
	}
	numstr[digits] = '\0';
	for (--digits; sum; --digits)
	{
		numstr[digits] = (sum % 10) + '0';
		sum /= 10;
	}
	return (numstr);
}

