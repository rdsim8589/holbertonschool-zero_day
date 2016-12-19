#include "my_shell.h"

/**
 * _memset - fill first n bytes of memory area
 * @s: char type pointer
 * @b: constant byte
 * @n: number of bytes to be filled
 *
 * Return: char pointer to memory area s
 */
char *_memset(char *s, char b, unsigned int n)
{
	unsigned int i;

	for (i = 0; i < n; i++)
		s[i] = b;
	return (s);
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
	while (c[i])
	{
		free(c[i]);
		i++;
	}
	free(c);
}

/**
 * _realloc - reallocate a memory block using malloc and free
 * @ptr: pointer to previously called memory (from malloc(old_size))
 * @old_size: size in bytes of memory for ptr
 * @new_size: size in bytes of new memory block
 *
 * Return: pointer to new memory, or NULL
 */
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size)
{
	char *new_ptr, *ptrcopy;
	unsigned int i;

	if (new_size == 0 && ptr != NULL)
	{
		free(ptr);
		return (NULL);
	}
	if (new_size == old_size)
		return (ptr);

	new_ptr = malloc(new_size);
	if (new_ptr == NULL)
		return (NULL);

	if (ptr == NULL)
		return (new_ptr);
	ptrcopy = ptr;
	i = 0;
	while (i < old_size && i < new_size)
	{
		new_ptr[i] = ptrcopy[i];
		i++;
	}
	free(ptr);
	return (new_ptr);
}
