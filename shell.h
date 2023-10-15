#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <errno.h>

extern char **environ;

/**
 * struct dir_list - definition for a node in dir_l list
 * @dir: directory path
 * @next: pointer to next node
 */

typedef struct dir_list
{
	char *dir;
	struct dir_list *next;
} dir_l;

void prompt(void);
char *readline(void);
char **_strtok(char *str, char *delim);
char *_getenv(const char *name);
dir_l *add_node(dir_l **head, char *dir);
void free_list(dir_l *head);
dir_l *get_path_dir(char *path);
char *get_location(char *name);
char *searchfile(dir_l *head, char *name);
int isProgPath(char *path);
int execute_cmd(char **args, char **env);
void exitShell(char **arg);
void free_args2(char **arg);

#endif
