#include <stdio.h>

/**
 * main - print all arguments without using agrc
 *
 * Return: 0
 */
int main(int argc, char *argv[])
{
	if (argc <= 0)
		return (1);
	if (argv == NULL)
		return (2);

	while (argc)
	{
		printf("%s\n", *argv);
		argv++;
		argc--;
	}
	return (0);
}
