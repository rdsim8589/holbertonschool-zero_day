#include "my_shell.h"

/**
 * _abs - helper for _itoa; computes absolute value of an integer
 * @i: interger to computer
 *
 * Return: absolute value;
 */
int _abs(int i)
{
	if (i < 0)
	{
		i = i * -1;
		return (i);
	}
	else
		return (i);
}

/**
 * _itoa - convert integer to string
 * @num: integer to convert
 *
 * Return: pointer to string
 */
char *_itoa(int num)
{
	int i;
	char *str;

	i = 0;
	if (num / 10 != 0)
		i = _itoa(num / 10);
	str = malloc(sizeof(*str) * _strlen(num));
	if (str == NULL)
		return (NULL);
	else if (num < 0)
		str[i++] = '-';
	/* make sure i is positive */
	str[i++] = _abs(num % 10) + '0';
	str[i] = '\0';

	return (str);
}
