#include "shell.h"

/**
 * _strtk_dup - returns pointer to new mem alloc space which contains copy
 * @strtodup: string to be duplicated
 * Return: a pointer to the new duplicated string
 */
char *_strdup(char *strtk_dup)
{
	char *copy;

	int len, i;

	if (strtk_dup == 0)
		return (NULL);

	for (len = 0; strtk_dup[len]; len++)
		;
	copy = malloc((len + 1) * sizeof(char));

	for (i = 0; i <= len; i++)
		copy[i] = strtk_dup[i];

	return (copy);
}

/**
 * _strcmpr - compares two strings
 * @strcmp1: first string, of two, to be compared in length
 * @strcmp2: second string, of two, to be compared
 * Return: 0 on success, anything else is a failure
 */
int _strcmpr(char *strcmp1, char *strcmp2)
{
	int i;

	i = 0;
	while (strcmp1[i] == strcmp2[i])
	{
		if (strcmp1[i] == '\0')
			return (0);
		i++;
	}
	return (strcmp1[i] - strcmp2[i]);
}

/**
 * _strcat - concatenates two strings
 * @strc1: first string
 * @strc2: second string
 * Return: pointer
 */
char *_strcat(char *strc1, char *strc2)
{
	char *sumstring;
	unsigned int len1, len2, sumlen, i, j;

	len1 = 0;
	len2 = 0;
	if (strc1 == NULL)
		len1 = 0;
	else
	{
		for (len1 = 0; strc1[len1]; len1++)
			;
	}
	if (strc2 == NULL)
		len2 = 0;
	else
	{
		for (len2 = 0; strc2[len2]; len2++)
			;
	}
	sumlen = len1 + len2 + 2;
	sumstring = malloc(sumlen * sizeof(char));
	if (sumstring == NULL)
		return (NULL);
	for (i = 0; i < len1; i++)
		sumstring[i] = strc1[i];
	sumstring[i] = '/';
	for (j = 0; j < len2; j++)
		sumstring[i + 1 + j] = strc2[j];
	sumstring[len1 + len2 + 1] = '\0';
	return (sumstring);
}

/**
 * _puts - writes a string to standard output
 * @str: string to write
 *
 * Return: number of chars printed or -1 on failure
 */
ssize_t _puts(char *str)
{
	ssize_t num, len;

	num = _strlen(str);
	len = write(STDOUT_FILENO, str, num);
	if (len != num)
	{
		perror("Fatal Error");
		return (-1);
	}
	return (len);
}

/**
 * _strlen - returns the length of a string
 * @str: string to be measured
 * Return: length of string
 */
unsigned int _strlen(char *str)
{
	unsigned int len;

	len = 0;

	for (len = 0; str[len]; len++)
		;
	return (len);
}

