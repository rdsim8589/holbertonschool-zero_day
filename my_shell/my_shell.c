#include "holberton.h"

typedef void (*sighandler_t)(int);
char c = '\0';

/**
 * handle_signal - handles the CTRL ^C input
 * @signo: signal number
 *
 * Return: void
 */
void handle_signal(int signo)
{
	printf("\n[MY_SHELL]$ ");
	fflush(stdout);
}

/**
 * main - main function
 * @argc: number of arguments
 * @argv: pointer to arguments
 * @envp: pointer to environmental variables
 *
 * Return: 0
 */
int main(int argc, char *argv[], char *envp[])
{
	char *buffer;
	size_t i, c;

	signal(SIGINT, SIG_IGN);
	signal(SIGINT, handle_signal);
	printf("[MY_SHELL]$ ");

	i = 32;
	buffer = malloc(sizeof(*buffer) * i);
	if (buffer == NULL)
		return (1);

	i = getline(&buffer, &i, stdin);
	printf("[MY_SHELL]$ %s", buffer);
	free(buffer);
	return 0;
}
