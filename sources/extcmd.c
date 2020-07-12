#include "shell.h"


int ext_cmd(char **args){
    int rc = fork();
    int c;
    if (rc < 0) {
         fprintf(stderr, "fork failed\n");
         exit(1);
    }else if (rc == 0) {
          if (execvp(args[0], args) < 0) {
	          c=-1;
           }
                       
    }else{
          wait(NULL);
    }
}


