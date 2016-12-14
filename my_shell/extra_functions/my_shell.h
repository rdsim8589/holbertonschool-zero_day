#ifndef MY_SHELL
#define MY_SHELL
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

int _getchar(void);
char *_strdup(char *str);
int _strcmp(char *s1, const char *s2);
char *_getenv(const char *name);

#endif /* ifndef MY_SHELL */
