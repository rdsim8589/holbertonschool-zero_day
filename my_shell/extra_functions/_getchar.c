#include "my_shell.h"

/**
 * _getchar - unbuffered single character input
 *
 * Return: int
 */
int _getchar(void)
{
	unsigned char c;
	int i;

	i = read(STDIN_FILENO, &c, 1);
	if (i == 1)
		return (c);
	return (EOF);
}

int main()
{
	printf("Hit any key, then hit RETURN.\n");
	printf ("The key you hit was '%c'.\n", _getchar());
	printf ("Bye!\n");

	return (0);
}
/*
int main(void)
{
	int ch;

	while (1)
	{
		ch = _getchar();
		if (ch == EOF)
			break;
		printf("%c", ch);
	}

	return 0;
}
*/
