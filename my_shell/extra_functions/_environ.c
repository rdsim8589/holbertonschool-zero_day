#include <stdio.h>
#include <unistd.h>

/**
 * main - print environmental variables using environ
 *
 * Return: 0
 */
int main(void)
{
	extern char **environ;
	int i;

	while (environ[i])
		printf("%s\n", environ[i++]);
	return (0);
}
