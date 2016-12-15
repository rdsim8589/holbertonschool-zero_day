#include "my_shell.h"

/**
 * _fork - fork a command while maintaining main process
 * @c: pointer to a pointer to a new command
 * @env: pointer to array of environmental variables
 *
 * Return: void
 */
void _fork(char **c, char **env)
{
	int i, f;

	f = fork();
	if (f == -1)
		write(2, "Fail", 4);
	else if (f == 0)
		execve(c[0], c, env);
	else
		wait(&i);
	return;
}

/**
 * _free - free called command
 * @c: pointer to a pointer to command to be freed
 *
 * Return: void
 */
void _free(char **c)
{
	int i;

	i = 0;
	while(c[i])
	{
		free(c[i]);
		i++;
	}
	free(c);
}

/**
 * main - my shell
 *
 * Return: 0
 */
int main(int argc, char *argv[], char *env[])
{
	char **command;
	char *line;

	/* read input from stdin */
	while (1)
	{
		write(1, "[MY_SHELL]$ ", 12);
		line = readline(0);
		com = strtok(line, " ");
		_fork(command, env);
		_free(command);
		free(line);
	}
}
