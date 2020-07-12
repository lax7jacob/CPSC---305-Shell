#include "shell.h"
#include <errno.h>


//uses pipe() and dup2 to handle | 
int pipe_handler(char **parsed, char **parsedpipe){

    int pipefd[2];
    pid_t p1, p2;

    if (pipe(pipefd) < 0) {
        printf("\nPipe could not be initialized");
        return 1;
    }
    p1 = fork();
    if (p1 < 0) {
        printf("\nCould not fork");
        return 1;
    }

    if (p1 == 0) {
        // Child 1 executing..
        // It only needs to write at the write end
        close(pipefd[0]);
        dup2(pipefd[1], STDOUT_FILENO);
        close(pipefd[1]);

        if (execvp(parsed[0], parsed) < 0) {
            printf("\nCould not execute command");
            exit(1);
        }
    } else {
        // Parent executing
        p2 = fork();

        if (p2 < 0) {
            printf("\nCould not fork");
            return 1;
        }

        // Child 2 executing..
        // It only needs to read at the read end
        if (p2 == 0) {
            close(pipefd[1]);
            dup2(pipefd[0], STDIN_FILENO);
            close(pipefd[0]);
            if (execvp(parsedpipe[0], parsedpipe) < 0) {
                printf("\nCould not execute command");
                exit(1);
            }
        } else {
            // parent executing, waiting for two children
	     close(pipefd[0]);
             close(pipefd[1]);
             wait(NULL);
	    
        }
    }
    return 0;
}
