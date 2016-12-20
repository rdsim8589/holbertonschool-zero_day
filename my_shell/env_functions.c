#include "my_shell.h"

/**
 * _getenv - get an environmental variable
 * @name: name of environmental variable
 *
 * Return: pointer to the value in the environment, or NULL if no match
 */
char *_getenv(char *c, char **env)
{
	int i;
	char *str, *temp;
	char **var;

	i  = 0;
	while (env[i])
	{
		str = _strdup(env[i]);
		if (str == NULL)
			return (NULL);
		var = _strtok(str, "=");
		/* check _strtok fail */
		comp = _strcmp(var[0], c);
		/* check _strcmp fail */
		if (comp == 0)
		{
			temp = env[i];
			while (*temp != '=')
				temp++;
			temp++;
			str = _strdup(temp);
			if (str == NULL)
				return (NULL);
			_free(var);
			return (str);
		}
		i++;
	}
	_free(var);
	return (NULL);
}

/**
 * _fork - fork a command while maintaining main process
 * @c: pointer to a pointer to a new command
 * @env: pointer to an array of environmental variables
 *
 * Return: void
 */
void _fork(char **command, char ***env)
{
	int i, f;
	char *c;

	c = command[0];
	/* check if command is builtin */
	if (_builtin(command, env))
		return;
	c = find_path(c, *env);
	if (c == NULL)
	{
		write(2, command[0], _strlen(command[0]));
		write(2, ": not found\n", 12);
		/* check write failure */
		return;
	}
	/* initiate child process */
	f = fork();
	if (f == -1)
		write(2, "Fail", 4);
	/* check for write failure */
	else if (f == 0)
		execve(c[0], c, env);
	/* check for execve command failure */
	else
	{
		wait(&i);
		update_status(status, env); /* write this function */
	}
	free(c);
	return;
}

/**
 * seg_num - helper function for _strtok; finds number of segments
 * @line: pointer to line being split
 * @sep: value evaluated as a separator
 *
 * Return: number of segments in @line
 */
int seg_num(char *line, char sep)
{
	int i;

	if (line == NULL)
		return (-1);
	i = 0;
	while (*line)
	{
		while (*line == sep)
			line++;
		if (*line == '\0')
			break;
		while (*line && *line != '\0')
			line++;
		i++;
	}
	return (i);
}

/**
 * seg_strlen - helper function for _strtok; finds length of each segment
 * @line: segment being evaluated
 * @sep: value evaluated as a separator
 *
 * Return: length of segment
 */
int seg_strlen(char *line, char sep)
{
	int i;

	i = 0;
	while (line[i] && line[i] != sep)
		i++;
	return (i);
}

/**
 * _strtok - split a string into a sequence of tokens
 * @line: line being split
 * @sep: value being used as separator
 *
 * Return: pointer to an array of tokens
 */
char **_strtok(char *line, char sep)
{
	char **token;
	char *ptr;
	int num, len;

	num = seg_num(line, sep);
	if (num <= 0)
		return (NULL);
	/* +2 for initial char value and trailing '\0' */
	token = malloc(sizeof(char *) * (num + 2));
	if (token == NULL)
		return (NULL);
	num = 0;
	while (*line)
	{
		while (*line == sep)
			line++;
		len = seg_strlen(line, sep);
		token[num] = malloc(sizeof(*ptr) * (len + 1));
		ptr = token[num];
		while (*line && *line != sep)
		{
			*ptr = *line;
			ptr++;
			line++;
		}
		while (*line == sep)
			line++;
		*ptr = 0;
		num++;
	}
	token[num] = 0;
	return (token);
}
