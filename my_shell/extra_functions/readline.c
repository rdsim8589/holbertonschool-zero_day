#include <stdio.h>
#include <stdlib.h>

/**
 * main - take input from user and print it back to stdout
 *
 * Return: 0
 */
int main(void)
{
	char *buffer;
	size_t input;

	input = 32;
	buffer = malloc(sizeof(*buffer) * input);
	if (buffer == NULL)
		return (1);

	printf("$$ ");
	input = getline(&buffer, &input, stdin);
	printf("%s", buffer);
	free(buffer);

	return (0);
}
