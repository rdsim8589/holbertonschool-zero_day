#ifndef MY_SHELL
#define MY_SHELL
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>

/* string_functions */
int _putchar(char c);
int _printstring(char *string);
int _strlen(char *s);
char *_strncpy(char *dest, char *src, int n);
char *_strcat(char *dest, char *src);
/* string_functions2 */
int _cstrlen(char **s);
char *_strdup(char *str);
int _strcmp(char *s1, const char *s2);
char *readline(int fd);
int _atoi(char *s);
/* string_functions3 */
int _abs(int i);
char *_itoa(int num);
/* memory_functions */
char *_memset(char *s, char b, unsigned int n);
void _free(char **c);
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size);
/* environment_functions */
char *_getenv(char *c, char **env);
void _fork(char **command, char ***env);
int seg_num(char *line, char sep);
int seg_strlen(char *line, char sep);
char **_strtok(char *line, char sep);
/* environment_functions2 */
void env_update(int current, char ***env);
/* builtin_functions */
int _bstrcomp(char *s1, char *s2);
void _exit(char **command, char **env);
/* path_functions */
void *find_path(char *command, __attribute__((unused)) char **env);
int check_path(char *c);

#endif /* #ifndef MY_SHELL */
