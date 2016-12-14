#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * main - split a string to an array of each word of the string
 * @argc: number of arguments
 * @argv: pointer to arguments
 *
 * Return: pointer to array of each word
 */
int main(int argc, char *argv[])
{
	char *str, *delim, *word;

	if (argc != 3)
		return (1);

	str = argv[1];
	delim = argv[2];
	word = strtok(str, delim);

	while (word != NULL)
	{
		printf("%s\n", word);
		word = strtok(NULL, delim);
	}
	return (0);
}
