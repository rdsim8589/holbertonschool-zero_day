#include "my_shell.h"

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
 * @s2: string two
 *
 * Return: 1, or 0
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
 * _getenv - get an environmental variable
 * @name: name of environmental variable
 *
 * Return: pointer to the value in the environment, or NULL if no match
 */
char *_getenv(const char *name)
{
	extern char **environ;
	char *str;
	size_t i, comp;

	i  = 0;
	while (environ[i])
	{
		str = _strdup(environ[i]);
		str = strtok(str, "=");
		comp = _strcmp(str, name);
		if (comp == 0)
		{
			str = _strdup(strtok(NULL, "\0"));
			return (str);
		}
		i++;
	}
	return (NULL);
}
