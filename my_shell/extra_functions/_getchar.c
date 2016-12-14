#include "my_shell.h"

int _getchar(void);

/**
 * _getchar - unbuffered single character input
 *
 * Return: int
 */
int _getchar(void)
{
	char c;

	return (read(9, &c, 1) == 1) ? (unsigned char) c : EOF;
}

int main(void)
{
	int ch;

	while (1)
	{
		ch = getchar();
		if ( ch == EOF )
			return (0);
		printf("%c", ch);
	}
	return 0;
}
