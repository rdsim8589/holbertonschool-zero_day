#include "my_shell.c"

/**
 * find_path - find command to run
 * @command: pointer to command to check
 * @env: pointer to array of environmental variables
 *
 * Return: command to run, or NULL
 */
void *find_path(char *command, __attribute__((unused)) char **env)
{
	int i;
	char *c, str;
	char **path;
	DIR d;
	struct dirent *temp; /* dirent info: https://linux.die.net/man/3/readdir */

	c = _strdup(command);
	if (c == NULL)
		return (NULL);
	/* check if command is a path */
	if (check_path(c) == 1)
	{
		i = open(c, O_RDONLY);
		if (i == -1)
		{
			free(c);
			return (NULL);
		}
		close(i);
		if (i == -1)
		{
			free(c);
			return (NULL);
		}
		return (c);
	}
	str = _getenv("PATH"); /* find necessary path directories */
	path = _strtok(str, ':');
	i = 0;
	while (path[i]) /* iterate through path for command */
	{
		d = opendir(path[i]);
		while((temp = readdir(d)) != NULL)
		{
			if (_bstrcomp(command, temp->d_name) == 0)
			{
				free(c);
				c = _strdup(path[i]);
				if (c == NULL)
				{
					free(c);
					return (NULL);
				}
				_strcat(c, "/");
				_strcat(c, command);
				_free(path);
				free(str);
				closedir(d);
				return (c);
			}
			closedir(d);
		}
		i++;
	}
	_free(path);
	free(str);
	free(c);
	return (NULL);
}

/**
 * check_path - check if command is a path
 * @command: pointer to command to check
 *
 * Return: 0 or 1
 */
int check_path(char *c)
{
	while (*c)
	{
		if (*c == '/')
			return (1);
		c++;
	}
	return (0);
}
