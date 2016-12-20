#include "my_string.c"

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
	env_set(); /* in progress */
	free(status);
	free(string);
}
