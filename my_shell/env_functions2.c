#include "my_shell.h"

/**
 * init_env - move environmental variables to the heap
 * @env: pointer to pointer to array of environmental variables
 *
 * Return: pointer to array of environmental variables
 */
char **init_env(char ***env)
{
	char **local;
	char *copy;
	int i, size;

	local = *env;
	size = _cstrlen(local);
	local = malloc((sizeof(*local) * size) + 1);
	if (local == NULL)
		return (NULL);
	i = 0;
	while (i < size)
	{
		copy = _strdup(*env[i]);
		if (copy == NULL)
			return (NULL);
		local[i] = copy;
		i++;
	}
	local[size] = '\0';
	*env = local;
	env_update(0, env);
	return (local);
}

/**
 * create_env - create environmental variables
 * @name: pointer to name of variable
 * @value: pointer to value of variable
 * @new: pointer to new environmental variable
 *
 * Return: void
 */
void create_env(char *name, char *value, char *new)
{
	while (*name) /* set new name */
	{
		*new = *name;
		new++;
		name++;
	}
	*new = '=';
	new++;
	while (*value) /* set new value */
	{
		*new = *value;
		new++;
		value++;
	}
	*new = '\0';
}

/**
 * val_location - find location of a given environmental variable
 * @env: pointer to array of environmental variables
 * @comp: variable to search for
 *
 * Return: location or -1 if fail
 */
int val_location(char **env, char *comp)
{
	int i;
	char **var;

	i = 0;
	while (env[i])
	{
		var = _strtok(env[i], "=");
		/* if found */
		if (_bstrcomp(env[0], comp) == 0)
		{
			_free(var);
			return (i);
		}
		_free(var);
		i++;
	}
	return (-1);
}

/**
 * env_set - set an environmental variable
 * @name: pointer to variable name
 * @env_val: pointer to variable value
 * @env: pointer to pointer to array of environmental variables
 *
 * Return: void
 */
void env_set(char *name, char *env_val, char ***env)
{
	char **local;
	char *val;
	int val_location, i;

	val = malloc(sizeof(char) * (_strlen(name) + _strlen(env_val)));
	if (val == NULL)
		return;

	local = *env;
	val_location = env_location(local, name); /* write this */
	create_env(name, env_val, val);
	if (val_location >= 0)
	{
		free(local[val_location]);
		local[val_location] = val;
		return;
	}
	/* otherwise add to env */
	i = _cstrlen(local);
	local = _realloc(local, i, (i * sizeof(*local)));
	local[i] = val;
	local[i + 1] = NULL;
	*env = local;
}

/**
 * env_update - update the status of environmental value
 * @current: current status
 * @env: pointer to pointer to array of environmental variables
 *
 * Return: void
 */
void env_update(int current, char ***env)
{
	char *str, *status;

	str = malloc(sizeof(*str) * 2);
	if (str == NULL)
		return;
	status = _itoa(current);
	str[0] = '?';
	str[1] = 0;
	env_set(str, status, env);
	free(status);
	free(string);
}
