#ifndef __SHELL_H__
#define __SHELL_H__
// program header
#include <dirent.h>
#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <unistd.h>
#include <stdlib.h>
#include <stddef.h>
#include <errno.h>
#include <fcntl.h>
#include <assert.h>



//defined delim
#define LSH_TOK_BUFSIZE 64
//#define LSH_TOK_DELIM " \t\r\n\a"
//#define PIPE_TOK_DELIM "|\t\r\n\a"
#define LSH_RL_BUFSIZE 1024
#define LSH_CMD_BUFSIZE 32
#endif

#ifndef __BASIC_FUNC__
#define __BASIC_FUNC__
// handler function

char *read_line(void);
char **parse_line(char *line);
void prompt(void);
int  cd(char **args);
int pwd(char **args);
int sh_exit(char **args);
int sh_mkdir(char **args, int size);
int fork_cmd(char **args);
int int_cmd(char **args);
int sh_ls(char **args, int size);
int sh_cat(char **args);
int sh_grep(char **args, int size);
void signal_handler(int signo);
void proc_signal_handler(int signo);
int check_cmd(char **args);
int pipe_handler(char **args, char **args1);
void file_in(char **args, char **args1);
void file_out(char **args, char **args2);
int size(char **args);
void bg_process(char **args);
#endif

