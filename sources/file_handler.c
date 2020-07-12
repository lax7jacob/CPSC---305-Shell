#include "shell.h"
#include <stdbool.h>

// runs "<"  
void file_in(char **args, char **args2) {

    int out, pid;
    if((pid = fork()) < 0){
	perror("Fork error");
    }else if(pid == 0){
   	 if ((out = open(args[0], O_CREAT|O_TRUNC|O_WRONLY, 0644)) == -1){
	      printf("File wrong");

          }
    

    dup2(out , STDOUT_FILENO);
    close(out);
     if (execvp(args2[0], args2) < 0) {
                printf("\nCould not execute command 2..");
                exit(1);
            }

    }else{

    close(out);
    wait(NULL);


    }
}

// runs ">"
void file_out(char **args, char **args2) {

    int in, pid;
    if((pid = fork()) < 0){
        perror("Fork error");
    }else if(pid == 0){
         if ((in = open(args[0], O_RDONLY)) == -1) {
              printf("File can't input");

          }


    dup2(in , STDIN_FILENO);
    close(in);
     if (execvp(args2[0], args2) < 0) {
                printf("\nCould not execute command 2..");
                exit(1);
            }

    }else{

    close(in);
    wait(NULL);


    }
}

//runs "&" background task
void bg_process(char **args){
	int s = size(args);
        bool found = true;
        int pid = fork();
        if (pid < 0){
        	perror("Error (pid < 0)");
        }
        if (pid == 0) {
            if (found) {
               args[s-1] = NULL;
                s--;
            }

           execvp(args[0], args);
           perror("execvp error");
        } 

}

//gets the size of the arguments 

int size(char **args){
    int size = 0;
    int i = 0;
    while(args[i] != NULL){
        size = size+1;
          i++;
    }
    return size;
}

//handles signals
void signal_handler(int signo)
{
        if (signo == SIGINT)
        {
                fprintf(stdout, "\n");
                prompt();
                fflush(stdout);
                signal(SIGINT, signal_handler);
        }
}



