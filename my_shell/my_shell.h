#ifndef MY_SHELL
#define MY_SHELL
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>

/* string functions */
int _putchar(char c);
int _printstring(char *string);
int _strlen(char *s);
char *_strncpy(char *dest, char *src, int n);
char *_strcat(char *dest, char *src);
char *_strdup(char *str);
int _strcmp(char *s1, const char *s2);
char *readline(int fd);
/* memory functions */
char *_memset(char *s, char b, unsigned int n);
void _free(char **c);
/* environment functions */
char *_getenv(const char *name);
/* command functions */
void _fork(char **c, char **env);

#endif /* #ifndef MY_SHELL */
