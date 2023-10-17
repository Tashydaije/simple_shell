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
char **_strtok(char *str, int *num_args);
char *_getenv(const char *name);
dir_l *add_node(dir_l **head, char *dir);
void free_list(dir_l **head);
dir_l *get_path_dir(dir_l **head, char *path);
char *get_location(char *command, char **tokens, char *argv[]);
char *searchfile(dir_l *head, char *name);
int isProgPath(char *path);
int execute_cmd(char **args, char **env);
int execute_builtin(char *command, char **args,
char *env_path, char **argv);
void exitShell(char **arg);
void free_args2(char **arg);
char *print_env(void);
void update_cmd(char **args, int index, char *arg);
void process_command(char *command,char **argv, char **env);
void free_tokens(char **tokens);
void handle_exit(char **args, char **argv);
void handle_env(void);



#endif
