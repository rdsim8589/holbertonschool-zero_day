#include "my_shell.h"

/**
 * _cstrlen - helper function for builtins; find length of command
 * @s: pointer to pointer to strin
 *
 * Return: length of s
 */
int _cstrlen(char **s)
{
	int l;

	l = 0;
	while (s[l])
		l++;
	return (l);
}

/**
 * _strdup - copy a string
 * @str: string
 *
 * Return: pointer to copy
 */
char *_strdup(char *str)
{
	char *s;
	unsigned int i, n;

	if (str == NULL)
		return (NULL);
	i = 0;
	while (str[i])
		i++;
	s = malloc((i * sizeof(char)) + 1);
	if (s == NULL)
		return (NULL);
	n = 0;
	while (n < i)
	{
		s[n] = str[n];
		n++;
	}
	s[n] = '\0';
	return (s);
}

/**
 * _strcmp - compare two strings
 * @s1: string one
 * @s2: const type string two
 *
 * Return: 1 or 0
 */
int _strcmp(char *s1, const char *s2)
{
	int i;

	if (s1 == NULL || s2 == NULL)
		return (1);
	i = 0;
	while (s1[i] != '\0')
	{
		if (s1[i] >  s2[i])
			return (s1[i] - s2[i]);
		if (s1[i] < s2[i])
			return (s1[i] - s2[i]);
		i++;
	}
	if (s1[i] == '\0' && s2[i] == '\0')
		return (0);
	else
		return (1);
}

/**
 * readline - read given line
 * @fd: file descriptor
 *
 * Return: pointer to stored read string
 */
char *readline(int fd)
{
	char *buffer, *line;
	unsigned int max, max_plus, i;
	char c;

	/* max length of a given line */
	max = 128;
	buffer = malloc(sizeof(*buffer) * max);
	if (buffer == NULL)
		return (NULL);
	read(fd, &c, 1);
	while (c != '\n')
	{
		if (i == max)
		{
			max_plus = max + 128;
			buffer = _realloc(buffer, max, max_plus);
			if (buffer == NULL)
				return (NULL);
			max = max_plus;
		}
		c = buffer[i];
		i++;
		read(fd, &c, 1);
	}
	buffer[i] = '\0';
	line = malloc(sizeof(*line) * (i + 1));
	if (line == NULL)
		return (NULL);
	line = _strdup(buffer);
	free(buffer);
	return (line);
}

/**
 * _atoi - convert string to integer
 * @s: string to convert
 *
 * Return: integer
 */
int _atoi(char *s)
{
	int number, i, neg;

	neg = 1;
	i = number = 0;
	while ((s[i] < '0' || s[i] > '9') && s[i] != 0)
	{
		if (s[i] == '-')
			neg = neg * -1;
		i++;
	}
	while ((s[i] >= '0' && s[i] <= '9') && s[i] != 0)
	{
		if (number >= 0)
		{
			number = number * 10 - (s[i] - '0');
			i++;
		}
		else
		{
			number = number * 10 - (s[i] - '0');
			i++;
		}
	}
	neg = neg * -1;
	return (number * neg);
}
